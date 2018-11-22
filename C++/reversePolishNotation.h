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
		Converts a mathematical equation from in-fix notation to post-fix
		notation then solves for the answer.
******************************************************************************/

#pragma once

#include <string>
#include <cctype>
#include <stack>
#include <map>
//#include <vector>
#include <cmath>
#include <stdexcept>

#include "stringUtils.h"
#include "Primitives/primitives.h"
#include "Primitives/double.h"

using std::string;
using std::stack;
using std::map;
//using std::vector;
using std::invalid_argument;
using std::pow;
using std::to_string;
using std::isalpha;
using std::isblank;
using std::shared_ptr;

namespace day {

	class ReversePolishNotation {

	private:

		enum precedenceLevel { OPENING_PARENTHESIS, ADD_SUB, MUL_DIV_MOD, EXP, CLOSING_PARENTHESIS };

		// Generic prefix for values in equation
		const char DEFAULT_ARG_PREFIX = '`';
		// Default slot for inserted -1 values
		const char DEFAULT_UNARY_MINUS_SIGN = '#';
	public:

		/******************************************************************************
			Function Name: evaluateEquation

			Des:
				Evaluates the equation to find the answer

			Params:
				equation - type const char *, the equation to be evaluated
				length - type int, the length of the param equation.

			Returns:
				type shared_ptr<Primitive>, the answer to the equation
		******************************************************************************/
		shared_ptr<Primitive> evaluateEquation(const char *equation, int length);

		/******************************************************************************
			Function Name: stripValuesFromEquation

			Des:
				Strips values from the equation and replaces them with letters

			Params:
				equation - type const char *, the data the number is to be
					extracted from.
				length - type int, the length of the param equation.
				values - type map<string, shared_ptr<Primitive>>, output map
					containing all values corresponding to the variables in param
					equation.

			Returns:
				type string, the equation with all values replaced with letters

			Throws:
				Throws exception if the equation is invalid.

			Note:
				Named variables in the equation must begin with an alphabetical
					character
		******************************************************************************/
		string stripValuesFromEquation(const char *equation, int length, map<string, shared_ptr<Primitive>> &values);

		/******************************************************************************
			Function Name: convertInfixToPostFix

			Des:
				Takes an equation that uses in-fix notation and converts it to
					post-fix notation.

			Params:
				equation - type const char *, the list of operands and operators
					sorted in postfix notation. All bool's are expected to have been
					replaced with letters. Case matters so 'A' is not equal to 'a.'
					Example input: (A+B)*C.
				length - type int, the length of the param equation.

			Returns:
				type string, the in-fix equation converted to post-fix.

			Throws:
				Throws exception if the equation is invalid.
		******************************************************************************/
		string convertInfixToPostFix(const char *equation, int length);

		/******************************************************************************
			Function Name: calcResult

			Des:
				Calculates the result of the equation used with the values.

			Params:
				equation - type const char *, the list of operands and operators
					sorted in postfix notation. All bool's are expected to have been
					replaced with letters. Case matters so 'A' is not equal to 'a.'
					Example input: AB+c*.
				length - type int, the length of the param equation.
				values - type map<string, shared_ptr<Primitive>>, array containing
					all values corresponding to the variables in param equation.

			Returns:
				type shared_ptr<Primitive>, result of the equation.

			Throws:
				Throws exception if the equation is unsolvable.
		******************************************************************************/
		shared_ptr<Primitive> calcResult(const char *equation, int length, map<string, shared_ptr<Primitive>> &values);

	private:

	/******************************************************************************
		Function Name: getNumber

		Des:
			Extract a numerical value from the string starting from the specified
				location.

		Params:
			data - type char *, the data the number is to be extracted from.
			length - type int, the length of the param data.
			start - type int, starting location in param data
			end - type int &, output to return the location of the last char of
				the number

		Returns:
			type shared_ptr<Primitive>, the wrapped value after it has been extracted
	******************************************************************************/
		shared_ptr<Primitive> getNumber(const char *data, int length, int start, int &end);

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
		char nextVariable(int &nextArgument);

		/******************************************************************************
			Function Name: isLowerPrecedence

			Des:
				Checks if the first operator has lower precedence than the second
					operator.

			Params:
				firstOperator - type char, the first operator.
				secondOperator - type char, the second operator.

			Returns:
				type bool, is the first operator lower precedence than the second one,
					otherwise false.
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
				Pops the top two Primitive's off the top of the stack.

			Params:
				operandStack - type stack<shared_ptr<Primitive>> &, is a stack
					containing all unprocessed operands.
				value1 - type shared_ptr<Primitive>, output to get the first int in
					the equation.
				value2 - type shared_ptr<Primitive>, output to get the second int in
					the equation.

			Throws:
				Throws exception if the there are less than 2 operands on the stack.
		******************************************************************************/
		void getOperandsFromStack(stack<shared_ptr<Primitive>> &operandStack, shared_ptr<Primitive> value1, shared_ptr<Primitive> value2);
	};
}