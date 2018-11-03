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

				if(algorithm[i] != ')')
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
		if(operatorStack.top() != '(')
			postFixString += operatorStack.top();

		operatorStack.pop();
	}

	return postFixString;
}

double ReversePolishNotation::calcResult(const char *algorithm, int length, double variables[]) {

	if (algorithm == nullptr)
		throw invalid_argument("Algorithm is null");

	if (variables == nullptr)
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
					operandStack.push(variables[algorithm[i] - 'a']);
				else if (algorithm[i] >= 'A' && algorithm[i] <= 'Z')
					operandStack.push(variables[algorithm[i] - 'A' + 26]);
		};
	}

	result = operandStack.top();
	operandStack.pop();

	if (!operandStack.empty())
		throw invalid_argument("Algorithm is invalid");

	return result;
}

bool ReversePolishNotation::calcResult(const char *algorithm, int length, bool variables[]) {

	if (algorithm == nullptr)
		throw invalid_argument("Algorithm is null");

	if (variables == nullptr)
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
					operandStack.push(variables[algorithm[i] - 'a']);
				else if (algorithm[i] >= 'A' && algorithm[i] <= 'Z')
					operandStack.push(variables[algorithm[i] - 'A' + 26]);
		};
	}

	result = operandStack.top();
	operandStack.pop();

	if (!operandStack.empty())
		throw invalid_argument("Algorithm is invalid");

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

void ReversePolishNotation::getOperandsFromStack(stack<double> operandStack, double &num1, double &num2) {

	if (operandStack.size() < 2)
		throw invalid_argument("Algorithm is invalid");

	num2 = operandStack.top();
	operandStack.pop();
	num1 = operandStack.top();
	operandStack.pop();
}

void ReversePolishNotation::getOperandsFromStack(stack<bool> operandStack, bool &bool1, bool &bool2) {

	if (operandStack.size() < 2)
		throw invalid_argument("Algorithm is invalid");

	bool2 = operandStack.top();
	operandStack.pop();
	bool1 = operandStack.top();
	operandStack.pop();
}