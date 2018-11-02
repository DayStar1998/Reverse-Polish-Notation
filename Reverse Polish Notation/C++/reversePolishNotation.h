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
	File Name: reversePolishNotation.h

	Author: Matthew Day

	Description:
		TODO: Write description for file
******************************************************************************/

#pragma once

#include <string>
#include <stack>
#include <cmath>
#include <stdexcept>

using std::string;
using std::stack;
using std::pow;
using std::invalid_argument;

class ReversePolishNotation {

public:

	/******************************************************************************
		Function Name: convertToRPN

		Des:
			TODO: Write description

		Params:
			TODO: Write description for method parameters
			algorithm - type char *,
			length - type int,
			variables - type double,

		Returns:
			TODO: Write description for method return value
			string
	******************************************************************************/
	string convertToRPN(char *algorithm, int length, double variables[]);

	/******************************************************************************
		Function Name: calcResult

		Des:
			Calculates the result of the algorithm used with the values

		Params:
			algorithm - type char *, the list of operands and operators sorted
				in postfix notation. All numbers are expected to have been replaced
				with letters. Case matters so 'A' is not equal to 'a.'
				Example input: AB+c*.
			length - type int, the length of the param algorithm.
			variables - type double [], array containing all values corresponding
				to the letters in param algorithm

		Returns:
			type double, result of the algorithm.

		Note:
			Throws exception if the algorithm is unsolvable
	******************************************************************************/
	double calcResult(char *algorithm, int length, double variables[]);

	/******************************************************************************
		Function Name: calcResult

		Des:
			Calculates the result of the algorithm used with the values

		Params:
			algorithm - type char *, the list of operands and operators sorted
				in postfix notation. All bool's are expected to have been replaced
				with letters. Case matters so 'A' is not equal to 'a.'
				Example input: AB=c|.
			length - type int, the length of the param algorithm.
			variables - type bool [], array containing all values corresponding
				to the letters in param algorithm

		Returns:
			type bool, result of the algorithm.

		Note:
			Warning: Each operator is assumed to be a separate comparison. '=' is 
				equivalent to the '==' operator. However, '==' is the equivalent
				of typing '====' which would have a different result than expected
			Throws exception if the algorithm is unsolvable.
	******************************************************************************/
	bool calcResult(char *algorithm, int length, bool variables[]);

private:
	
	/******************************************************************************
		Function Name: getOperandsFromStack
		
		Des:
			Pops the top two int's off the top of the stack.
			
		Params:
			operandStack - type stack<bool>, is a stack containing all unprocessed.
				operands
			num1 - type int &, output to get the first int in the equation.
			num2 - type int &, output to get the second int in the equation.

		Note:
			Throws exception if the there are less than 2 operands on the stack.
	******************************************************************************/
	void getOperandsFromStack(stack<double> operandStack, double &num1, double &num2);
	
	/******************************************************************************
		Function Name: getOperandsFromStack
		
		Des:
			Pops the top two bool's off the top of the stack.
			
		Params:
			operandStack - type stack<bool>, is a stack containing all unprocessed
				operands.
			bool1 - type bool &, output to get the first bool in the equation.
			bool2 - type bool &, output to get the second bool in the equation.

		Note:
			Throws exception if the there are less than 2 operands on the stack.
	******************************************************************************/
	void getOperandsFromStack(stack<bool> operandStack, bool &bool1, bool &bool2);
};