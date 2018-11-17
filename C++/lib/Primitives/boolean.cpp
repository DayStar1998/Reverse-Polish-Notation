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
	File Name: boolean.cpp

	Author: Matthew Day

	Description:
		Implementation file for boolean.h
******************************************************************************/

#include "boolean.h"

namespace day {

	// Assignment
	Boolean& Boolean::operator=(Primitive &primitive) {

		if (primitive.getType() == BOOLEAN)
			this->setBool(primitive.getBool());
		else
			throw new exception("Unsupported operation");

		return *this;
	}

	string Boolean::toString() {

		return to_string(data);
	}

	// Logical NOT
	Primitive Boolean::operator!() {

		Boolean result(!this->getBool());

		return result;
	}

	// Logical AND
	Primitive Boolean::operator&&(Primitive &primitive) {

		Boolean result;

		if (primitive.getType() == BOOLEAN)
			result.setBool(this->getBool() && primitive.getBool());
		else
			throw new exception("Unsupported operation");

		return result;
	}

	// Logical OR
	Primitive Boolean::operator||(Primitive &primitive) {

		Boolean result;

		if (primitive.getType() == BOOLEAN)
			result.setBool(this->getBool() || primitive.getBool());
		else
			throw new exception("Unsupported operation");

		return result;
	}
}