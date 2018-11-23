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

			char backOfResultString = result[result.length() - 1];

			// Check whether a minus sign is being used to subtract or to make the number negative
			if (equation[i] == '-' && (i == 0 || (isOperator(backOfResultString) && backOfResultString != ')'))) {

				if (i + 1 == length)
					throw invalid_argument("Equation is invalid");

				if (equation[i + 1] == '(') {

					// Place DEFAULT_UNARY_MINUS_SIGN to differentiate from a regular minus sign
					result.push_back(DEFAULT_UNARY_MINUS_SIGN);
				} else if (isdigit(equation[i + 1])) {

					// Replace the number in the resulting equation with an argument prefixed with DEFAULT_ARG_PREFIX
					string key = DEFAULT_ARG_PREFIX + to_string(nextArgument++);
					result.append(key);
					values[key] = getNumber(equation, length, i, endPos);

					i = endPos;
				} else if (equation[i + 1] == '-') {

					// TODO: Support post- pre- incrementation/decrementation
					// Skip this '-' and the next one because negativing a negative number makes it positive
					i++;
					continue;
				} else {

					// Place DEFAULT_UNARY_MINUS_SIGN to differentiate from a regular minus sign
					result.push_back(DEFAULT_UNARY_MINUS_SIGN);

					// Get the variable from the string and prefix it with DEFAULT_ARG_PREFIX
					string variable = DEFAULT_ARG_PREFIX + getVar(equation, length, i + 1, endPos);

					// Add the variable to the string
					result.append(variable);

					// If the variable doesn't exist then a null value is set for it and it is assumed the variable will be initialized during this equation
					if (!values.count(variable))
						values[variable] = make_shared<Primitive>();

					i = endPos;
				}
			} else if (isdigit(equation[i]) || equation[i] == '.') {

				// Replace the number in the resulting equation with an argument
				string key = DEFAULT_ARG_PREFIX + to_string(nextArgument++);
				result.append(key);
				values[key] = getNumber(equation, length, i, endPos);

				i = endPos;
			} else if (isalpha(equation[i])) {

				// Get the variable from the string and prefix it with DEFAULT_ARG_PREFIX
				string variable = DEFAULT_ARG_PREFIX + getVar(equation, length, i, endPos);

				// Add the variable to the string
				result.append(variable);

				// If the variable doesn't exist then a null value is set for it and it is assumed the variable will be initialized during this equation
				if (!values.count(variable))
					values[variable] = make_shared<Primitive>();

				i = endPos;
			// If the equation is in the format of a(b) then it is expanded to a*(b)
			} else if (equation[i] == '(' && i > 0 && isalnum(equation[i - 1])) {

				result.push_back('*');
				result.push_back(equation[i]);
			// If the equation is in the format of (a)b then it is expanded to (a)*b
			} else if (equation[i] == ')' && i + 1 != length && isalnum(equation[i + 1])) {

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

		stack<string> operatorStack;
		string postFixString;

		for (int i = 0; i < length; i++) {

			// Variables are pushed to the post-fix string
			if (!isOperator(equation[i])) {

				postFixString += equation[i];
			} else {

				string currentOperator = getOperator(equation, length, i, i);

				if (operatorStack.size() == 0) {

					operatorStack.push(currentOperator);
				//If the current operator has lower precedence than the operator on top of the operator stack
				} else if (isLowerPrecedence(operatorStack.top(), currentOperator)) {

					// If the current operator is a ')' then pop operators off the stack into the post-fix string
					//		until the matching '(' is found
					if (equation[i] == ')') {

						while (operatorStack.top() != "(") {

							if (operatorStack.empty())
								throw invalid_argument("Too many closing parenthesis");

							postFixString += DEFAULT_ARG_PREFIX + operatorStack.top();
							operatorStack.pop();
						}

						// Remove '(' from the stack
						operatorStack.pop();
					} else {

						operatorStack.push(currentOperator);
					}
				} else {

					// '(' always has lowest precedence, but should not be removed until the matching ')' is found
					if (equation[i] != '(') {

						if (operatorStack.empty())
							throw invalid_argument("Too many closing parenthesis");

						postFixString += DEFAULT_ARG_PREFIX + operatorStack.top();
						operatorStack.pop();
					}

					operatorStack.push(currentOperator);
				}
			}
		}

		while (!operatorStack.empty()) {

			// Allow input to leave off the closing parenthesis at the end
			if (operatorStack.top() != "(")
				postFixString += DEFAULT_ARG_PREFIX + operatorStack.top();

			operatorStack.pop();
		}

		return postFixString;
	}

	shared_ptr<Primitive> ReversePolishNotation::calcResult(const char *equation, int length, map<string, shared_ptr<Primitive>> &values) {

		if (equation == nullptr)
			throw invalid_argument("Equation is null");

		stack<string> operandStack;
		shared_ptr<Primitive> result;
		string label1, label2;

		// Counter for temporary labels for calculated answers that are pushed back on the operandStack
		int tmpLabelNums = 0;

		for (int i = 0; i < length; i++) {

			if (equation[i] == DEFAULT_ARG_PREFIX) {

				if (isOperator(equation[i + 1])) {

					string currentOperator = getOperator(equation, length, i + 1, i);

					// Assignment
					if (currentOperator == "=") {

						// Assign the value of the second operand to the first
						getOperandsFromStack(operandStack, label1, label2);
						values.at(label1) = values.at(label2);
						operandStack.push(label1);
					// Multiplication
					} else if (currentOperator == "*") {

						// Multiplies operands with each other
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) * *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Division
					} else if (currentOperator == "/") {

						// Divides second operand from the first
						// Handling divide by 0 exception is out of scope and an exception will be thrown
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) / *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Modulation
					} else if (currentOperator == "%") {

						// Modulates first operand by the second
						// Handling divide by 0 exception is out of scope
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) % *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Addition
					} else if (currentOperator == "+") {

						// Add the first operand to the second operand
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) + *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Subtraction
					} else if (currentOperator == "-") {

						// Subtracts second operand from the first
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) - *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Bitwise OR
					} else if (currentOperator == "|") {

						// First operand bitwise OR the second operand
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) | *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Bitwise AND
					} else if (currentOperator == "&") {

						// First operand bitwise AND the second operand
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) & *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Bitwise NOT
					} else if (currentOperator == "~") {

						// Bitwise NOT the operand
						label1 = operandStack.top();
						operandStack.pop();

						values[to_string(tmpLabelNums)] = ~*values.at(label1);
						operandStack.push(to_string(tmpLabelNums++));
					// Bitwise XOR
					} else if (currentOperator == "^") {

						// First operand XOR the second operand
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) ^ *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Logical NOT
					} else if (currentOperator == "!") {

						// Get boolean off top of the stack and NOT it
						label1 = operandStack.top();
						operandStack.pop();
						values[to_string(tmpLabelNums)] = !*values.at(label1);
						operandStack.push(to_string(tmpLabelNums++));
					// Logical AND
					} else if (currentOperator == "&&") {

						// First operand AND the second operand
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) && *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					// Logical OR
					} else if (currentOperator == "||") {

						// First operand OR the second operand
						getOperandsFromStack(operandStack, label1, label2);
						values[to_string(tmpLabelNums)] = *values.at(label1) || *values.at(label2);
						operandStack.push(to_string(tmpLabelNums++));
					} else
						throw invalid_argument(currentOperator + " is not yet supported");
				// Unary minus
				} else if (equation[i + 1] == DEFAULT_UNARY_MINUS_SIGN) {

					label1 = operandStack.top();
					operandStack.pop();
					values[to_string(tmpLabelNums)] = -*values.at(label1);
					operandStack.push(to_string(tmpLabelNums++));
				} else if (isalnum(equation[i + 1])) {

					string argument = getVar(equation, length, i + 1, i);
					operandStack.push(DEFAULT_ARG_PREFIX + argument);
				} else
					throw invalid_argument("Equation is invalid");
			}
		}

		result = values.at(operandStack.top());
		operandStack.pop();

		if (!operandStack.empty())
			throw invalid_argument("Equation is invalid");

		return result;
	}

	shared_ptr<Primitive> ReversePolishNotation::getNumber(const char *data, int length, int start, int &end) {

		shared_ptr<Primitive> result;

		bool hasDecimal = false;

		// TODO: Support casting numbers, eg. 1f to float

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

	bool ReversePolishNotation::isLowerPrecedence(string firstOperator, string secondOperator) {

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

	ReversePolishNotation::precedenceLevel ReversePolishNotation::getPrecedenceLevel(string curOperator) {

		precedenceLevel result;

		// TODO: Add support for operation assignment
		switch (curOperator[0]) {

			// Opening parenthesis
			case '(':

				result = OPENING_PARENTHESIS;
				break;
			// Assignment or equal to
			case '=':

				// Check if the operator is an assignment or a comparative equal to
				if (curOperator.length() == 2) {

					if (curOperator[1] == '=')
						result = EQUAL_NOT_EQUAL;
					else
						throw invalid_argument(curOperator + "is not a valid operator");
				} else
					result = OPERATION_ASSIGNMENT;

				break;
			// Logical NOT or not equal to
			case '!':

				// Check if the operator is a logical NOT or a comparative not equal to
				if (curOperator.length() == 2) {

					if (curOperator[1] == '=')
						result = EQUAL_NOT_EQUAL;
					else
						throw invalid_argument(curOperator + "is not a valid operator");
				} else
					result = BITWISE_LOGICAL_NOT;

				break;
			// Bitwise NOT
			case '~':

				result = BITWISE_LOGICAL_NOT;
				break;
			// Multiplication, division, or modulation
			case '*':
			case '/':
			case '%':

				result = MUL_DIV_MOD;
				break;
			// Addition or subtraction
			case '+':
			case '-':
				result = ADD_SUB;
				break;
			// Bitwise AND or logical AND
			case '&':

				// Check if the operator is a bitwise AND or a logical AND
				if (curOperator.length() == 2) {

					if (curOperator[1] == '&')
						result = LOGICAL_AND;
					else
						throw invalid_argument(curOperator + "is not a valid operator");
				} else
					result = BITWISE_AND;

				break;
			// Bitwise OR or logical OR
			case '|':

				// Check if the operator is a bitwise OR or a logical OR
				if (curOperator.length() == 2) {

					if (curOperator[1] == '|')
						result = LOGICAL_OR;
					else
						throw invalid_argument(curOperator + "is not a valid operator");
				} else
					result = BITWISE_OR;

				break;
			// Bitwise XOR
			case '^':

				result = BITWISE_XOR;
				break;
			// Greater than, greater than or equal to, or bitwise right shift
			case '>':

				// Check if the operator is a bitwise right shift, a greater than, or a greater than or equal to
				if (curOperator.length() == 2) {

					if (curOperator[1] == '>')
						result = BITWISE_LEFT_RIGHT_SHIFT;
					else if (curOperator[1] == '=')
						result = GREATER_LESSER_EQUAL;
					else
						throw invalid_argument(curOperator + "is not a valid operator");
				} else
					result = GREATER_LESSER_EQUAL;

				break;
			// Less than, less than or equal to, or bitwise left shift
			case '<':

				// Check if the operator is a bitwise left shift, a less than, or a less than or equal to
				if (curOperator.length() == 2) {

					if (curOperator[1] == '<')
						result = BITWISE_LEFT_RIGHT_SHIFT;
					else if (curOperator[1] == '=')
						result = GREATER_LESSER_EQUAL;
					else
						throw invalid_argument(curOperator + "is not a valid operator");
				} else
					result = GREATER_LESSER_EQUAL;

				break;
			// Closing parenthesis
			case ')':

				result = CLOSING_PARENTHESIS;
				break;
			default:

				throw invalid_argument(curOperator + "is not a valid operator");
		};

		return result;
	}

	void ReversePolishNotation::getOperandsFromStack(stack<string> &operandStack, string &value1, string &value2) {

		if (operandStack.size() < 2)
			throw invalid_argument("Equation is invalid");

		value2 = operandStack.top();
		operandStack.pop();
		value1 = operandStack.top();
		operandStack.pop();
	}
}