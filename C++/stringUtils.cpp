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

	double getNumber(const char *data, int length, int start, int &end) {

		double result;
		string number = "";
		int pos = start;

		// Skip the negative sign to avoid checking if the sign is relative to this number or just a minus sign
		if (data[start] == '-') {

			number.push_back('-');
			pos++;
		}

		// Avoid having to increment with every iteration to prevent it from not being set if the loop runs until equal to length
		end = length - 1;

		for (int i = pos; i < length; i++) {

			// Check if current char is a number or a decimal point
			if (isdigit(data[i]) || data[i] == '.')
				number.push_back(data[i]);
			else {

				end = i - 1;
				break;
			}
		}

		// Convert to double
		result = stod(number);

		return result;
	}
}