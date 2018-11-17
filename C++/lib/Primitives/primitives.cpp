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
	File Name: Primitive.cpp

	Author: Matthew Day

	Description:
		Implementation file for Primitive.h
******************************************************************************/

#include "primitives.h"

namespace day {

	Primitive::Type Primitive::getType() {

		return Primitive::TYPE;
	}

	Primitive& Primitive::operator=(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::Primitive::operator+(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator-(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator*(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator/(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator%(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive& Primitive::operator++() {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator++(int) {

		throw new exception("Unsupported operation");
	}

	Primitive& Primitive::operator--() {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator--(int) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator|(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator&(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator~() {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator^(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator<<(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator>>(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	bool Primitive::operator==(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	bool Primitive::operator!=(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	bool Primitive::operator>(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	bool Primitive::operator<(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	bool Primitive::operator>=(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	bool Primitive::operator<=(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	// Addition assignment
	Primitive& Primitive::operator+=(Primitive &primitive) {

		*this = (Primitive&)(*this + primitive);

		return *this;
	}

	// Subtraction assignment
	Primitive& Primitive::operator-=(Primitive &primitive) {

		*this = (Primitive&)(*this - primitive);

		return *this;
	}

	// Multiplication assignment
	Primitive& Primitive::operator*=(Primitive &primitive) {

		*this = (Primitive&)(*this * primitive);

		return *this;
	}

	// Division assignment
	Primitive& Primitive::operator/=(Primitive &primitive) {

		*this = (Primitive&)(*this / primitive);

		return *this;
	}

	// Modulation assignment
	Primitive& Primitive::operator%=(Primitive &primitive) {

		*this = (Primitive&)(*this % primitive);

		return *this;
	}

	// Bitwise AND assignment
	Primitive& Primitive::operator&=(Primitive &primitive) {

		*this = (Primitive&)(*this & primitive);

		return *this;
	}

	// Bitwise OR assignment
	Primitive& Primitive::operator|=(Primitive &primitive) {

		*this = (Primitive&)(*this | primitive);

		return *this;
	}

	// Bitwise XOR assignment
	Primitive& Primitive::operator^=(Primitive &primitive) {

		*this = (Primitive&)(*this ^ primitive);

		return *this;
	}

	// Shift left assignment
	Primitive& Primitive::operator<<=(Primitive &primitive) {

		*this = (Primitive&)(*this << primitive);

		return *this;
	}

	// Shift right assignment
	Primitive& Primitive::operator>>=(Primitive &primitive) {

		*this = (Primitive&)(*this >> primitive);

		return *this;
	}

	Primitive Primitive::operator!() {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator&&(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}

	Primitive Primitive::operator||(Primitive &primitive) {

		throw new exception("Unsupported operation");
	}
}