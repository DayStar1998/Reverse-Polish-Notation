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

	string Boolean::toString() {

		string result;

		// Using to_string returns 0 or 1. Result should be "true" or "false"
		if (data)
			result = "true";
		else
			result = "false";

		return result;
	}

	// Assignment
	Boolean& Boolean::operator=(Primitive &primitive) {

		this->setBool(primitive.getBool());

		return *this;
	}

	// Bitwise NOT
	shared_ptr<Primitive> Boolean::operator~() {

		shared_ptr<Primitive> result = make_shared<Boolean>(~this->getBool());

		return result;
	}

	// Bitwise AND
	shared_ptr<Primitive> Boolean::operator&(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		result->setBool(this->getBool() & primitive.getBool());

		return result;
	}

	// Bitwise OR
	shared_ptr<Primitive> Boolean::operator|(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		result->setBool(this->getBool() | primitive.getBool());

		return result;
	}

	// Bitwise XOR
	shared_ptr<Primitive> Boolean::operator^(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		result->setBool(this->getBool() ^ primitive.getBool());

		return result;
	}

	// Equal to
	shared_ptr<Primitive> Boolean::operator==(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		result->setBool(this->getBool() == primitive.getBool());

		return result;
	}

	// Not equal to
	shared_ptr<Primitive> Boolean::operator!=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		result->setBool(this->getBool() != primitive.getBool());

		return result;
	}

	// Logical NOT
	shared_ptr<Primitive> Boolean::operator!() {

		shared_ptr<Primitive> result = make_shared<Boolean>(!this->getBool());

		return result;
	}

	// Logical AND
	shared_ptr<Primitive> Boolean::operator&&(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		result->setBool(this->getBool() && primitive.getBool());

		return result;
	}

	// Logical OR
	shared_ptr<Primitive> Boolean::operator||(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		result->setBool(this->getBool() || primitive.getBool());

		return result;
	}
}