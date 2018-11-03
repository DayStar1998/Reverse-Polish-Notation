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

string ReversePolishNotation::stripValuesFromAlgorithm(const char *algorithm, int length, vector<double> &values) {

	if (algorithm == nullptr)
		throw invalid_argument("Algorithm is null");

	queue<double> valuesQueue;
	int numVariablesUsed = 0;
	string result = "";
	int endPos;

	for (int i = 0; i < length; i++) {

		// Skip whitespace
		if (isblank(algorithm[i]))
			continue;

		// Check whether a minus sign is being used to subtract or to make the number negative
		if (algorithm[i] == '-' && (i - 1 < 0 || (isOperator(algorithm[i - 1]) && algorithm[i - 1] != ')'))) {

			if (i == length)
				throw invalid_argument("Algorithm is invalid");

			if (algorithm[i + 1] == '(') {

				// Multiply result of calculations in parenthesis by -1 to substitute for making the number negative directly
				result.push_back(nextVariable(numVariablesUsed));
				valuesQueue.push(-1);
				result.push_back('*');
			} else {

				// Replace the number in the resulting algorithm with a variable
				result.push_back(nextVariable(numVariablesUsed));
				valuesQueue.push(getNumber(algorithm, length, i, endPos));

				i = endPos;
			}
		} else if (isdigit(algorithm[i])) {

			result.push_back(nextVariable(numVariablesUsed));
			valuesQueue.push(getNumber(algorithm, length, i, endPos));

			i = endPos;
		// if the algorithm is in the format of 5(6) then it is expanded to 5*(6)
		}else if (algorithm[i] == '(' && i > 0 && isdigit(algorithm[i - 1])) {

			result.push_back('*');
			result.push_back(algorithm[i]);
		// if the algorithm is in the format of (6)5 then it is expanded to (6)*5
		} else if (algorithm[i] == ')' && i + 1 != length && isdigit(algorithm[i + 1])) {

			result.push_back(algorithm[i]);
			result.push_back('*');
		} else
			result.push_back(algorithm[i]);
	}

	// Enter the numbers from valuesQueue into values
	for (int i = 0; !valuesQueue.empty(); i++) {

		values.push_back(valuesQueue.front());
		valuesQueue.pop();
	}

	return result;
}

string ReversePolishNotation::convertInfixToPostFix(const char *algorithm, int length) {

	if (algorithm == nullptr)
		throw invalid_argument("Algorithm is null");

	stack<char> operatorStack;
	string postFixString;

	for (int i = 0; i < length; i++) {

		// Variables are pushed to the post-fix string
		if (isalpha(algorithm[i]))
			postFixString += algorithm[i];
		else {

			if (operatorStack.size() == 0) {

				operatorStack.push(algorithm[i]);
				//IF the current operator has lower precedence than the operator on top of the operator stack
			} else if (isLowerPrecedence(operatorStack.top(), algorithm[i])) {

				if (algorithm[i] == ')') {

					while (operatorStack.top() != '(') {

						postFixString += operatorStack.top();
						operatorStack.pop();
					}

					// Remove '(' from the stack
					operatorStack.pop();
				} else {

					operatorStack.push(algorithm[i]);
				}
			} else {

				if (algorithm[i] != ')')
					throw invalid_argument("Too many closing parenthesis");

				if (algorithm[i] != '(') {

					postFixString += operatorStack.top();
					operatorStack.pop();
				}

				operatorStack.push(algorithm[i]);
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

double ReversePolishNotation::calcResult(const char *algorithm, int length, double values[]) {

	if (algorithm == nullptr)
		throw invalid_argument("Algorithm is null");

	if (values == nullptr)
		throw invalid_argument("Variables is invalid");

	stack<double> operandStack;
	double result;
	double num1, num2;

	for (int i = 0; i < length; i++) {

		switch (algorithm[i]) {

			case '+':

				// Adds operands to each other
				getOperandsFromStack(operandStack, num1, num2);
				operandStack.push(num1 + num2);
				break;
			case '-':

				// Subtracts second operands from the first
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

				// Convert letter to the number it represents and add it to the operand stack
				if (algorithm[i] >= 'a' && algorithm[i] <= 'z')
					operandStack.push(values[algorithm[i] - 'a']);
				else if (algorithm[i] >= 'A' && algorithm[i] <= 'Z')
					operandStack.push(values[algorithm[i] - 'A' + 26]);
		};
	}

	result = operandStack.top();
	operandStack.pop();

	if (!operandStack.empty())
		throw invalid_argument("Algorithm is invalid");

	return result;
}

bool ReversePolishNotation::calcResult(const char *algorithm, int length, bool values[]) {

	if (algorithm == nullptr)
		throw invalid_argument("Algorithm is null");

	if (values == nullptr)
		throw invalid_argument("Variables is invalid");

	stack<bool> operandStack;
	bool result;
	bool bool1, bool2;

	for (int i = 0; i < length; i++) {

		switch (algorithm[i]) {

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

				// Convert letter to the boolean it represents and add it to the operand stack
				if (algorithm[i] >= 'a' && algorithm[i] <= 'z')
					operandStack.push(values[algorithm[i] - 'a']);
				else if (algorithm[i] >= 'A' && algorithm[i] <= 'Z')
					operandStack.push(values[algorithm[i] - 'A' + 26]);
		};
	}

	result = operandStack.top();
	operandStack.pop();

	if (!operandStack.empty())
		throw invalid_argument("Algorithm is invalid");

	return result;
}

char ReversePolishNotation::nextVariable(int &numVariablesUsed) {

	char result;

	if ('a' + numVariablesUsed <= 'z')
		result = 'a' + numVariablesUsed;
	else if ('A' + numVariablesUsed - 26 <= 'Z')
		result = 'A' + numVariablesUsed - 26;
	else
		throw invalid_argument("Algorithm is too long");

	numVariablesUsed++;

	return result;
}

double ReversePolishNotation::getNumber(const char *algorithm, int length, int start, int &end) {

	double result;
	string number = "";
	int pos = start;

	// Skip the negative sign to avoid checking if the sign is relative to this number or just a minus sign
	if (algorithm[start] == '-') {

		number.push_back('-');
		pos++;
	}

	// Avoid having to increment with every iteration to prevent it from not being set if the loop runs till equal to length
	end = length - 1;

	for (int i = pos; i < length; i++) {

		// Check if current char is a number or a decimal point
		if (isdigit(algorithm[i]) || algorithm[i] == '.')
			number.push_back(algorithm[i]);
		else {

			end = i - 1;
			break;
		}
	}

	// Convert to double
	result = stod(number);

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

void ReversePolishNotation::getOperandsFromStack(stack<double> operandStack, double &value1, double &value2) {

	if (operandStack.size() < 2)
		throw invalid_argument("Algorithm is invalid");

	value2 = operandStack.top();
	operandStack.pop();
	value1 = operandStack.top();
	operandStack.pop();
}

void ReversePolishNotation::getOperandsFromStack(stack<bool> operandStack, bool &value1, bool &value2) {

	if (operandStack.size() < 2)
		throw invalid_argument("Algorithm is invalid");

	value2 = operandStack.top();
	operandStack.pop();
	value1 = operandStack.top();
	operandStack.pop();
}