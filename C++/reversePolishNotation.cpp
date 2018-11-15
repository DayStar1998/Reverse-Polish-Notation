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

	Outline:
		Public Functions:
			evaluateEquation

		Private Functions
			stripValuesFromEquation
			convertInfixToPostFix
			calcResult
			calcResult
			nextVariable
			isOperator
			isLowerPrecedence
			getPrecedenceLevel
			getOperandsFromStack
			getOperandsFromStack
******************************************************************************/

#include "reversePolishNotation.h"

double ReversePolishNotation::evaluateEquation(const char *equation, int length) {

	vector<double> values;
	double result;

	string editedEquation = stripValuesFromEquation(equation, length, values);

	editedEquation = convertInfixToPostFix(editedEquation.c_str(), editedEquation.size());

	result = calcResult(editedEquation.c_str(), editedEquation.size(), values);

	return result;
}

string ReversePolishNotation::stripValuesFromEquation(const char *equation, int length, vector<double> &values) {

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

		// Check whether a minus sign is being used to subtract or to make the number negative
		if (equation[i] == '-' && (i == 0 || (isOperator(equation[i - 1]) && equation[i - 1] != ')'))) {

			if (i + 1 == length)
				throw invalid_argument("Equation is invalid");

			if (equation[i + 1] == '(') {

				// Multiply result of calculations in parenthesis by -1 to substitute for making the result negative directly
				result.push_back(DEFAULT_NEGATIVE_ONE_VALUE);
				result.push_back('*');
			} else {

				// Replace the number in the resulting equation with an argument
				result.append(DEFAULT_ARG_PREFIX + to_string(nextArgument++));
				values.push_back(getNumber(equation, length, i, endPos));

				i = endPos;
			}
		} else if (isdigit(equation[i]) || equation[i] == '.') {

			// Replace the number in the resulting equation with an argument
			result.append(DEFAULT_ARG_PREFIX + to_string(nextArgument++));
			values.push_back(getNumber(equation, length, i, endPos));

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

double ReversePolishNotation::calcResult(const char *equation, int length, vector<double> &values) {

	if (equation == nullptr)
		throw invalid_argument("Equation is null");

	stack<double> operandStack;
	double result;
	double num1, num2;

	for (int i = 0; i < length; i++) {

		switch (equation[i]) {

			case '+':

				// Adds operands to each other
				getOperandsFromStack(operandStack, num1, num2);
				operandStack.push(num1 + num2);
				break;
			case '-':

				// Subtracts second operand from the first
				getOperandsFromStack(operandStack, num1, num2);
				operandStack.push(num1 - num2);
				break;
			case '*':

				// Multiplies operands with each other
				getOperandsFromStack(operandStack, num1, num2);
				operandStack.push(num1 * num2);
				break;
			case '/':

				// Divides second operand from the first
				getOperandsFromStack(operandStack, num1, num2);
				operandStack.push(num1 / num2);
				break;
			case '%':

				// Modulates first operand by the second
				// WARNING: Conversion to integer causes decimal data to be lost
				getOperandsFromStack(operandStack, num1, num2);
				operandStack.push((int)num1 % (int)num2);
				break;
			case '^':

				// Sets first operand to the power of the second
				getOperandsFromStack(operandStack, num1, num2);
				operandStack.push(pow(num1, num2));
				break;
			default:

				if (equation[i] == DEFAULT_NEGATIVE_ONE_VALUE) {

					operandStack.push(-1);
				} else if (equation[i] == DEFAULT_ARG_PREFIX) {

					int argumentNum = (int)getNumber(equation, length, i + 1, i);
					operandStack.push(values[argumentNum]);
				} else throw invalid_argument("Equation is invalid");
				//// Convert letter to the number it represents and add it to the operand stack
				//if (equation[i] >= (double)'a' && equation[i] <= (double)'z')
				//	operandStack.push(values[equation[i] - 'a']);
				//else if (equation[i] >= (double)'A' && equation[i] <= (double)'Z')
				//	operandStack.push(values[equation[i] - 'A' + 26]);
				//else throw invalid_argument("Equation is too long");
		};
	}

	result = operandStack.top();
	operandStack.pop();

	if (!operandStack.empty())
		throw invalid_argument("Equation is invalid");

	return result;
}

bool ReversePolishNotation::calcResult(const char *equation, int length, vector<bool> &values) {

	if (equation == nullptr)
		throw invalid_argument("Equation is null");

	stack<bool> operandStack;
	bool result;
	bool bool1, bool2;

	for (int i = 0; i < length; i++) {

		switch (equation[i]) {

			case '!':

				// Get boolean off top of the stack and NOT it
				bool1 = operandStack.top();
				operandStack.pop();
				operandStack.push(!bool1);
				break;
			case '&':

				// Confirm if both the first operand and the second operand are true
				getOperandsFromStack(operandStack, bool1, bool2);
				operandStack.push(bool1 && bool2);

				break;
			case '|':

				// Confirm if either the first operand or the second operand are true
				getOperandsFromStack(operandStack, bool1, bool2);
				operandStack.push(bool1 || bool2);

				break;
			case '=':

				// Confirm if the first operand equals the second operand
				getOperandsFromStack(operandStack, bool1, bool2);
				operandStack.push(bool1 == bool2);

				break;
			default:

				if (equation[i] == DEFAULT_ARG_PREFIX) {

					int argumentNum = (int)getNumber(equation, length, i + 1, i);
					operandStack.push(values[argumentNum]);
				}
				// Convert argument to the boolean it represents and add it to the operand stack
		/*		if (equation[i] >= 'a' && equation[i] <= 'z')
					operandStack.push(values[equation[i] - 'a']);
				else if (equation[i] >= 'A' && equation[i] <= 'Z')
					operandStack.push(values[equation[i] - 'A' + 26]);*/
		};
	}

	result = operandStack.top();
	operandStack.pop();

	if (!operandStack.empty())
		throw invalid_argument("Equation is invalid");

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

bool ReversePolishNotation::isOperator(char value) {

	bool result = false;

	// TODO: Add support for bool operators

	switch (value) {

		case '(':
		case ')':
		case '^':
		case '*':
		case '/':
		case '+':
		case '-':

			result = true;
	};

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

void ReversePolishNotation::getOperandsFromStack(stack<double> &operandStack, double &value1, double &value2) {

	if (operandStack.size() < 2)
		throw invalid_argument("Equation is invalid");

	value2 = operandStack.top();
	operandStack.pop();
	value1 = operandStack.top();
	operandStack.pop();
}

void ReversePolishNotation::getOperandsFromStack(stack<bool> &operandStack, bool &value1, bool &value2) {

	if (operandStack.size() < 2)
		throw invalid_argument("Equation is invalid");

	value2 = operandStack.top();
	operandStack.pop();
	value1 = operandStack.top();
	operandStack.pop();
}