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
#include <queue>
#include <vector>
#include <cmath>
#include <stdexcept>

using std::string;
using std::stack;
using std::queue;
using std::vector;
using std::invalid_argument;
using std::pow;
using std::isalpha;
using std::isdigit;
using std::isblank;
using std::stod;

class ReversePolishNotation {

private:

	enum precedenceLevel { OPENING_PARENTHESIS, ADD_SUB, MUL_DIV_MOD, EXP, CLOSING_PARENTHESIS };
public:

	/******************************************************************************
		Function Name: stripValuesFromAlgorithm
		
		Des:
			Strips values from the algorithm and replaces them with letters
			
		Params:
			algorithm - type const char *, the data the number is to be
				extracted from.
			length - type int, the length of the param algorithm.
			values - type vector<double> &, output vector containing all values
				corresponding to the letters in param algorithm.
			
		Returns:
			type string, the algorithm with all values replaced with letters

		Throws:
			Throws exception if the algorithm is invalid.
	******************************************************************************/
	string stripValuesFromAlgorithm(const char *algorithm, int length, vector<double> &values);

	/******************************************************************************
		Function Name: convertInfixToPostFix

		Des:
			Takes an algorithm that uses in-fix notation and converts it to
				post-fix notation.

		Params:
			algorithm - type const char *, the list of operands and operators
				sorted in postfix notation. All bool's are expected to have been
				replaced with letters. Case matters so 'A' is not equal to 'a.'
				Example input: (A+B)*C.
			length - type int, the length of the param algorithm.

		Returns:
			type string, the in-fix algorithm converted to post-fix.

		Throws:
			Throws exception if the algorithm is invalid.
	******************************************************************************/
	string convertInfixToPostFix(const char *algorithm, int length);

	/******************************************************************************
		Function Name: calcResult

		Des:
			Calculates the result of the algorithm used with the values.

		Params:
			algorithm - type const char *, the list of operands and operators
				sorted in postfix notation. All bool's are expected to have been
				replaced with letters. Case matters so 'A' is not equal to 'a.'
				Example input: AB+c*.
			length - type int, the length of the param algorithm.
			values - type double [], array containing all values corresponding
				to the letters in param algorithm.

		Returns:
			type double, result of the algorithm.

		Throws:
			Throws exception if the algorithm is unsolvable.
	******************************************************************************/
	double calcResult(const char *algorithm, int length, double values[]);

	/******************************************************************************
		Function Name: calcResult

		Des:
			Calculates the result of the algorithm used with the values.

		Params:
			algorithm - type const char *, the list of operands and operators
				sorted in postfix notation. All bool's are expected to have been
				replaced with letters. Case matters so 'A' is not equal to 'a.'
				Example input: AB=c|.
			length - type int, the length of the param algorithm.
			values - type bool [], array containing all values corresponding
				to the letters in param algorithm.

		Returns:
			type bool, result of the algorithm.

		Throws:
			Throws exception if the algorithm is unsolvable.

		Note:
			Warning: Each operator is assumed to be a separate comparison. '=' is
				equivalent to the '==' operator. However, '==' is the equivalent
				of typing '====' which would have a different result than expected
	******************************************************************************/
	bool calcResult(const char *algorithm, int length, bool values[]);

private:

	/******************************************************************************
		Function Name: nextVariable
		
		Des:
			Get the next available variable
			
		Params:
			numVariablesUsed - type int &, modified input current total number of variables
				used, output to show the new total number of variables used
			
		Returns:
			type char, the next available variable

		Throws:
			Throws exception if all variables have been used
	******************************************************************************/
	char nextVariable(int &numVariablesUsed);

	/******************************************************************************
		Function Name: getNumber
		
		Des:
			Extract a numerical value from the string starting from the specified
				location.
			
		Params:
			algorithm - type char *, the data the number is to be extracted from.
			length - type int, the length of the param algorithm.
			start - type int, starting location in param algorithm
			end - type int &, output to return the location of the last char of
				the number
			
		Returns:
			type double, the value after it has been extracted
	******************************************************************************/
	double getNumber(const char *algorithm, int length, int start, int &end);

	/******************************************************************************
		Function Name: isOperator

		Des:
			Checks if the value is an operator.

		Params:
			value - type char, the value to be checked.

		Returns:
			type bool, true if it is an operator, otherwise false.

		Note:
			Does not support bool operators
			TODO: Add support for bool operators
	******************************************************************************/
	bool isOperator(char value);

	/******************************************************************************
		Function Name: isLowerPrecedence

		Des:
			Checks if the first operator has lower precedence than the second operator.

		Params:
			firstOperator - type char, the first operator.
			secondOperator - type char, the second operator.

		Returns:
			type bool, is the first operater lower precedence than the second one, otherwise false.
	******************************************************************************/
	bool isLowerPrecedence(char firstOperator, char secondOperator);

	/******************************************************************************
		Function Name: getPrecedenceLevel

		Des:
			Finds the precedence level of the operator.

		Params:
			curOperator - type char, the operator to be checked.

		Returns:
			type ReversePolishNotation::precedenceLevel, the level of precedence
				that the operator has.
	******************************************************************************/
	precedenceLevel getPrecedenceLevel(char curOperator);

	/******************************************************************************
		Function Name: getOperandsFromStack

		Des:
			Pops the top two int's off the top of the stack.

		Params:
			operandStack - type stack<bool>, is a stack containing all unprocessed
				operands.
			value1 - type int &, output to get the first int in the equation.
			value2 - type int &, output to get the second int in the equation.

		Throws:
			Throws exception if the there are less than 2 operands on the stack.
	******************************************************************************/
	void getOperandsFromStack(stack<double> operandStack, double &value1, double &value2);

	/******************************************************************************
		Function Name: getOperandsFromStack

		Des:
			Pops the top two bool's off the top of the stack.

		Params:
			operandStack - type stack<bool>, is a stack containing all unprocessed
				operands.
			value1 - type bool &, output to get the first bool in the equation.
			value2 - type bool &, output to get the second bool in the equation.

		Throws:
			Throws exception if the there are less than 2 operands on the stack.
	******************************************************************************/
	void getOperandsFromStack(stack<bool> operandStack, bool &value1, bool &value2);
};