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

	Class Name: ReversePolishNotation

	Description:
		Converts a mathematical algorithm from in-fix notation to post-fix
		notation then solves for the answer.

	Functions:
		string convertInfixToPostFix(char *algorithm, int length)
		double calcResult(char *algorithm, int length, double variables[])
		bool calcResult(char *algorithm, int length, bool variables[])
******************************************************************************/

#pragma once

#include <string>
#include <cctype>
#include <stack>
#include <cmath>
#include <stdexcept>

using std::string;
using std::stack;
using std::pow;
using std::invalid_argument;
using std::isalpha;

class ReversePolishNotation {

private:

	enum precedenceLevel { OPENING_PARENTHESIS, ADD_SUB, MUL_DIV_MOD, EXP, CLOSING_PARENTHESIS };
public:

	/******************************************************************************
		Function Name: convertInfixToPostFix

		Des:
			Takes an algorithm that uses in-fix notation and converts it to
				post-fix notation.

		Params:
			algorithm - type char *, the list of operands and operators sorted
				in in-fix notation. All numbers are expected to have been replaced
				with letters. Case matters so 'A' is not equal to 'a.'
				Example input: (A+B)*C.
			length - type int, the length of the param algorithm.

		Returns:
			type string, the in-fix algorithm converted to post-fix.
	******************************************************************************/
	string convertInfixToPostFix(const char *algorithm, int length);

	/******************************************************************************
		Function Name: calcResult

		Des:
			Calculates the result of the algorithm used with the values.

		Params:
			algorithm - type char *, the list of operands and operators sorted
				in postfix notation. All numbers are expected to have been replaced
				with letters. Case matters so 'A' is not equal to 'a.'
				Example input: AB+c*.
			length - type int, the length of the param algorithm.
			variables - type double [], array containing all values corresponding
				to the letters in param algorithm.

		Returns:
			type double, result of the algorithm.

		Note:
			Throws exception if the algorithm is unsolvable.
	******************************************************************************/
	double calcResult(const char *algorithm, int length, double variables[]);

	/******************************************************************************
		Function Name: calcResult

		Des:
			Calculates the result of the algorithm used with the values.

		Params:
			algorithm - type char *, the list of operands and operators sorted
				in postfix notation. All bool's are expected to have been replaced
				with letters. Case matters so 'A' is not equal to 'a.'
				Example input: AB=c|.
			length - type int, the length of the param algorithm.
			variables - type bool [], array containing all values corresponding
				to the letters in param algorithm.

		Returns:
			type bool, result of the algorithm.

		Note:
			Warning: Each operator is assumed to be a separate comparison. '=' is 
				equivalent to the '==' operator. However, '==' is the equivalent
				of typing '====' which would have a different result than expected
			Throws exception if the algorithm is unsolvable.
	******************************************************************************/
	bool calcResult(const char *algorithm, int length, bool variables[]);

private:

	
	/******************************************************************************
		Function Name: isLowerPrecedence
		
		Des:
			Checks if the first operator has lower precedence than the second operator
			
		Params:
			firstOperator - type char, the first operator
			secondOperator - type char, the second operator
			
		Returns:
			type bool, is the first operater lower precedence than the second one;
	******************************************************************************/
	bool isLowerPrecedence(char firstOperator, char secondOperator);

	
	/******************************************************************************
		Function Name: getPrecedenceLevel
		
		Des:
			Finds the precedence level of the operator
			
		Params:
			curOperator - type char, the operator to be checked
			
		Returns:
			type ReversePolishNotation::precedenceLevel, the level of precedence
				that the operator has
	******************************************************************************/
	precedenceLevel getPrecedenceLevel(char curOperator);
	
	/******************************************************************************
		Function Name: getOperandsFromStack
		
		Des:
			Pops the top two int's off the top of the stack.
			
		Params:
			operandStack - type stack<bool>, is a stack containing all unprocessed
				operands.
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