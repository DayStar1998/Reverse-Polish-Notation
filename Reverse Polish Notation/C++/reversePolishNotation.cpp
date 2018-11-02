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

// TODO: Document the function
string ReversePolishNotation::convertToRPN(char *algorithm, int length, double variables[]) {

	//TODO: Stub
}

double ReversePolishNotation::calcResult(char *algorithm, int length, double variables[]) {

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

bool ReversePolishNotation::calcResult(char *algorithm, int length, bool variables[]) {

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