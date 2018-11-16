
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
	File Name: stringUtils.h

	Author: Matthew Day

	Description:
		A set of operations that can be performed on a string
******************************************************************************/

#pragma once

#include <string>
#include <cctype>

using std::string;
using std::isdigit;
using std::stod;

namespace day {

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
			type double, the value after it has been extracted
	******************************************************************************/
	double getNumber(const char *data, int length, int start, int &end);
};