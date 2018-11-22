/******************************************************************************
	Copyright 2018 Matthew Day

	Licensed under the Apache License, Version 2.0 (the "License");
	you may not use this file except in compliance with the License.
	You may obtain a copy of the License at

	https://www.apache.org/licenses/LICENSE-2.0

	Unless required by applicable law or agreed to in writing, software
	distributed under the License is distributed on an "AS IS" BASIS,
	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	See the License for the specific language governing permissions and
	limitations under the License.
******************************************************************************/

/******************************************************************************
	File Name: reversePolishNotation.cpp

	Author: Matthew Day

	Description:
		Implementation file for reversePolishNotation.h
******************************************************************************/

#include "reversePolishNotation.h"

namespace day {

	shared_ptr<Primitive> ReversePolishNotation::evaluateEquation(const char *equation, int length) {

		// Recreated each time to avoid old invalid data being left from previous invalid equations
		map<string, shared_ptr<Primitive>> values;
		shared_ptr<Primitive> result;

		string editedEquation = stripValuesFromEquation(equation, length, values);

		editedEquation = convertInfixToPostFix(editedEquation.c_str(), editedEquation.size());

		result = calcResult(editedEquation.c_str(), editedEquation.size(), values);

		return result;
	}

	string ReversePolishNotation::stripValuesFromEquation(const char *equation, int length, map<string, shared_ptr<Primitive>> &values) {

		if (equation == nullptr)
			throw invalid_argument("Equation is null");

		string result = "";
		int endPos;

		// Counter value to show next available argument
		int nextArgument = 0;

		for (int i = 0; i < length; i++) {

			// Skip whitespace
			if (isblank(equation[i]))
				continue;

			// TODO: Fix to work when whitespace is before the minus sign
			// Check whether a minus sign is being used to subtract or to make the number negative
			if (equation[i] == '-' && (i == 0 || (isOperator(result[i - 1]) && result[i - 1] != ')'))) {

				if (i + 1 == length)
					throw invalid_argument("Equation is invalid");

				if (equation[i + 1] == '(') {

					// Place DEFAULT_UNARY_MINUS_SIGN to differentiate from a regular minus sign
					result.push_back(DEFAULT_UNARY_MINUS_SIGN);
				} else if(isdigit(equation[i + 1])){

					// Replace the number in the resulting equation with an argument
					string key = to_string(nextArgument++);
					result.append(DEFAULT_ARG_PREFIX + key);
					values.emplace(key, getNumber(equation, length, i, endPos));

					i = endPos;
				} else {

					// Place DEFAULT_UNARY_MINUS_SIGN to differentiate from a regular minus sign
					result.push_back(DEFAULT_UNARY_MINUS_SIGN);

					// Get the variable from the string
					string variable = getVar(equation, length, i + 1, endPos);

					// Insert prefix before the variable and skip the minus sign in the resulting equation
					result.append(DEFAULT_ARG_PREFIX + variable);

					// If the variable doesn't exist then a null value is set for it and it is assumed the variable will be initialized from outside of scope
					if(!values.count(variable))
						values.emplace(variable, Primitive());

					i = endPos;
				}
			} else if (isdigit(equation[i]) || equation[i] == '.') {

				// Replace the number in the resulting equation with an argument
				string key = to_string(nextArgument++);
				result.append(DEFAULT_ARG_PREFIX + key);
				values.emplace(key, getNumber(equation, length, i, endPos));

				i = endPos;
			} else if (isalpha(equation[i])) {

				// Get the variable from the string
				string variable = getVar(equation, length, i, endPos);

				// Insert prefix before the variable and skip the minus sign in the resulting equation
				result.append(DEFAULT_ARG_PREFIX + variable);

				// If the variable doesn't exist then a null value is set for it and it is assumed the variable will be initialized from outside of scope
				if (!values.count(variable))
					values.emplace(variable, Primitive());

				i = endPos;
			// if the equation is in the format of a(b) then it is expanded to a*(b)
			} else if (equation[i] == '(' && i > 0 && isdigit(equation[i - 1])) {

				result.push_back('*');
				result.push_back(equation[i]);
			// if the equation is in the format of (a)b then it is expanded to (a)*b
			} else if (equation[i] == ')' && i + 1 != length && isdigit(equation[i + 1])) {

				result.push_back(equation[i]);
				result.push_back('*');
			} else
				result.push_back(equation[i]);
		}

		return result;
	}

	string ReversePolishNotation::convertInfixToPostFix(const char *equation, int length) {

		if (equation == nullptr)
			throw invalid_argument("Equation is null");

		stack<char> operatorStack;
		string postFixString;

		for (int i = 0; i < length; i++) {

			// Variables are pushed to the post-fix string
			if (!isOperator(equation[i])) {

				postFixString += equation[i];
			} else {

				if (operatorStack.size() == 0) {

					operatorStack.push(equation[i]);
				//IF the current operator has lower precedence than the operator on top of the operator stack
				} else if (isLowerPrecedence(operatorStack.top(), equation[i])) {

					// IF the current operator is a ')' then pop operators off the stack into the post-fix string
					//		until the matching '(' is found
					if (equation[i] == ')') {

						while (operatorStack.top() != '(') {

							if (operatorStack.empty())
								throw invalid_argument("Too many closing parenthesis");

							postFixString += operatorStack.top();
							operatorStack.pop();
						}

						// Remove '(' from the stack
						operatorStack.pop();
					} else {

						operatorStack.push(equation[i]);
					}
				} else {

					// '(' always has lowest precedence, but should not be removed until the matching ')' is found
					if (equation[i] != '(') {

						if (operatorStack.empty())
							throw invalid_argument("Too many closing parenthesis");

						postFixString += operatorStack.top();
						operatorStack.pop();
					}

					operatorStack.push(equation[i]);
				}
			}
		}

		while (!operatorStack.empty()) {

			// Allow input to leave off the closing parenthesis at the end
			if (operatorStack.top() != '(')
				postFixString += operatorStack.top();

			operatorStack.pop();
		}

		return postFixString;
	}

	shared_ptr<Primitive> ReversePolishNotation::calcResult(const char *equation, int length, map<string, shared_ptr<Primitive>> &values) {

		if (equation == nullptr)
			throw invalid_argument("Equation is null");

		stack<shared_ptr<Primitive>> operandStack;
		shared_ptr<Primitive> result;
		shared_ptr<Primitive> primitive1, primitive2;

		for (int i = 0; i < length; i++) {

			switch (equation[i]) {

				// Arithmetic operators
				case '=':

					// Assign the value of the second operand to the first
					getOperandsFromStack(operandStack, primitive1, primitive2);
					// TODO: Should I be doing something else here?
					operandStack.push(primitive1 = primitive2);

					break;
				case '+':

					// Adds operands to each other
					getOperandsFromStack(operandStack, primitive1, primitive2);
					operandStack.push(*primitive1 + *primitive2);
					break;
				case '-':

					// Subtracts second operand from the first
					getOperandsFromStack(operandStack, primitive1, primitive2);
					operandStack.push(*primitive1 - *primitive2);
					break;
				case '*':

					// Multiplies operands with each other
					getOperandsFromStack(operandStack, primitive1, primitive2);
					operandStack.push(*primitive1 * *primitive2);
					break;
				case '/':

					// Divides second operand from the first
					// Handling divide by 0 exception is out of scope and an exception will be thrown
					getOperandsFromStack(operandStack, primitive1, primitive2);
					operandStack.push(*primitive1 / *primitive2);
					break;
				case '%':

					// Modulates first operand by the second
					// Handling divide by 0 exception is out of scope
					getOperandsFromStack(operandStack, primitive1, primitive2);
					operandStack.push(*primitive1 % *primitive2);
					break;
				case '|':

					// First operand bitwise OR the second operand
					getOperandsFromStack(operandStack, primitive1, primitive2);
					operandStack.push(*primitive1 | *primitive2);

					break;
				case '&':

					// First operand bitwise AND the second operand
					getOperandsFromStack(operandStack, primitive1, primitive2);
					operandStack.push(*primitive1 & *primitive2);

					break;
				case '~':

					// Bitwise NOT the operand
					primitive1 = operandStack.top();
					operandStack.pop();
					operandStack.push(~*primitive1);
					break;
				case '^':

					// First operand XOR the second operand
					getOperandsFromStack(operandStack, primitive1, primitive2);
					operandStack.push(*primitive1 ^ *primitive2);
					break;
				case '!':
					// Get boolean off top of the stack and NOT it
					primitive1 = operandStack.top();
					operandStack.pop();
					operandStack.push(!*primitive1);
					break;
				default:

					if (equation[i] == DEFAULT_UNARY_MINUS_SIGN) {

						primitive1 = operandStack.top();
						operandStack.pop();
						operandStack.push(-*primitive1);
					} else if (equation[i] == DEFAULT_ARG_PREFIX) {

						string argument = getVar(equation, length, i + 1, i);
						operandStack.push(values[argument]);
					} else throw invalid_argument("Equation is invalid");
			};
		}

		result = operandStack.top();
		operandStack.pop();

		if (!operandStack.empty())
			throw invalid_argument("Equation is invalid");

		return result;
	}

	shared_ptr<Primitive> ReversePolishNotation::getNumber(const char *data, int length, int start, int &end) {

		shared_ptr<Primitive> result;

		bool hasDecimal = false;

		// Get the number as a string
		string number = day::getNumber(data, length, true, start, end, hasDecimal);

		// Convert to Double or Integer
		if (hasDecimal)
			result = make_shared<Double>(stod(number));
		else
			result = make_shared<Integer>(stoi(number));

		return result;
	}

	char ReversePolishNotation::nextVariable(int &nextArgument) {

		char result;

		if ('a' + nextArgument <= 'z')
			result = 'a' + nextArgument;
		else if ('A' + nextArgument - 26 <= 'Z')
			result = 'A' + nextArgument - 26;
		else
			throw invalid_argument("Equation is too long");

		nextArgument++;

		return result;
	}

	bool ReversePolishNotation::isLowerPrecedence(char firstOperator, char secondOperator) {

		bool result;
		precedenceLevel firstPrecedenceLevel, secondPrecedenceLevel;

		firstPrecedenceLevel = getPrecedenceLevel(firstOperator);
		secondPrecedenceLevel = getPrecedenceLevel(secondOperator);

		if (firstPrecedenceLevel < secondPrecedenceLevel)
			result = true;
		else
			result = false;

		return result;
	}

	ReversePolishNotation::precedenceLevel ReversePolishNotation::getPrecedenceLevel(char curOperator) {

		precedenceLevel result;

		switch (curOperator) {

			case '(':

				result = OPENING_PARENTHESIS;
				break;
			case '+':
			case '-':

				result = ADD_SUB;
				break;
			case '*':
			case '/':
			case '%':

				result = MUL_DIV_MOD;
				break;
			case '^':

				result = EXP;
				break;
			case ')':

				result = CLOSING_PARENTHESIS;
				break;
			default:

				throw invalid_argument(curOperator + "is not a valid operator");
		};

		return result;
	}

	void ReversePolishNotation::getOperandsFromStack(stack<shared_ptr<Primitive>> &operandStack, shared_ptr<Primitive> value1, shared_ptr<Primitive> value2) {

		if (operandStack.size() < 2)
			throw invalid_argument("Equation is invalid");

		value2 = operandStack.top();
		operandStack.pop();
		value1 = operandStack.top();
		operandStack.pop();
	}
}