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
	File Name: stringUtils.cpp

	Author: Matthew Day

	Description:
		Implementation file for stringUtils.h
******************************************************************************/

#include "stringUtils.h"

namespace day {

	string getNumber(const char *data, int length, bool includeDecimal, int start, int &end, bool &hasDecimal) {

		string result = "";
		int pos = start;

		// Skip the negative sign to avoid checking if the sign is relative to this number or just a minus sign
		if (data[start] == '-') {

			result.push_back('-');
			pos++;
		}

		// Avoid having to increment with every iteration to prevent it from not being set if the loop runs until equal to length
		end = length - 1;

		hasDecimal = false;

		for (int i = pos; i < length; i++) {

			// Check if current char is a number or a decimal point
			if (isdigit(data[i]))
				result.push_back(data[i]);
			else if (data[i] == '.') {

				// Break if decimal point is a period instead of part of the number
				if (!includeDecimal)
					break;

				// Break if one decimal point has already been found. Second is seen as a period
				// TODO: Should this throw an exception or otherwise report back if it is an error?
				if (hasDecimal)
					break;

				hasDecimal = true;
				result.push_back(data[i]);
			} else {

				// Set end to the last char in the number
				end = i - 1;
				break;
			}
		}

		return result;
	}

	string getVar(const char *data, int length, int start, int &end) {

		string result;
		int pos = start;

		// Avoid having to increment with every iteration to prevent it from not being set if the loop runs until equal to length
		end = length - 1;

		for (int i = pos; i < length; i++) {

			// Check if current char is a alphabetical character or number
			if (isalnum(data[i]))
				result.push_back(data[i]);
			else {

				end = i - 1;
				break;
			}
		}

		return result;
	}

	bool isOperator(char value) {

		bool result = false;

		switch (value) {

			case '(':
			case ')':
			case '*':
			case '/':
			case '%':
			case '+':
			case '-':
			case '|':
			case '&':
			case '~':
			case '^':
			case '>':
			case '<':
			case '!':
			case '=':

				result = true;
		};

		return result;
	}
}