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

	string Primitive::typeName() {

		string result;

		switch (this->getType()) {

			case Type::VOID:

				result = "void";
				break;
			case Type::CHAR:

				result = "char";
				break;
			case Type::SHORT:

				result = "short";
				break;
			case Type::INTEGER:

				result = "integer";
				break;
			case Type::LONG:

				result = "long";
				break;
			case Type::FLOAT:

				result = "float";
				break;
			case Type::DOUBLE:

				result = "double";
				break;
			case Type::BOOLEAN:

				result = "boolean";
				break;
			default:

				throw new exception("Type is not supported, please add it");
		};

		return result;
	}

	// Assignment
	Primitive& Primitive::operator=(Primitive &primitive) {

		// TODO: Default case for if 'this' is type VOID
		string message = "Assignment '=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Addition
	Primitive Primitive::Primitive::operator+(Primitive &primitive) {

		string message = "Addition '+' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Subtraction
	Primitive Primitive::operator-(Primitive &primitive) {

		string message = "Subtraction '-' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Unary minus
	Primitive Primitive::operator-() {

		string message = "Unary minus '-' operation for type " + this->typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Multiplication
	Primitive Primitive::operator*(Primitive &primitive) {

		string message = "Multiplication '*' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Division
	Primitive Primitive::operator/(Primitive &primitive) {

		string message = "Division '/' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Modulation
	Primitive Primitive::operator%(Primitive &primitive) {

		string message = "Modulation '%' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Prefix incrementation
	Primitive& Primitive::operator++() {

		string message = "Prefix incrementation '++' operation for type " + this->typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Postfix incrementation
	Primitive Primitive::operator++(int) {

		string message = "Postfix incrementation '++' operation for type " + this->typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Prefix decrementation
	Primitive& Primitive::operator--() {

		string message = "Prefix decrementation '--' operation for type " + this->typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Postfix decrementation
	Primitive Primitive::operator--(int) {

		string message = "Postfix decrementation '--' operation for type " + this->typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Bitwise OR
	Primitive Primitive::operator|(Primitive &primitive) {

		string message = "Bitwise OR '|' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Bitwise AND
	Primitive Primitive::operator&(Primitive &primitive) {

		string message = "Bitwise AND '&' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Bitwise NOT
	Primitive Primitive::operator~() {

		string message = "Bitwise NOT '~' operation for type " + this->typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Bitwise XOR
	Primitive Primitive::operator^(Primitive &primitive) {

		string message = "Bitwise XOR '^' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Bitwise left shift
	Primitive Primitive::operator<<(Primitive &primitive) {

		string message = "Bitwise left shift '<<' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Bitwise right shift
	Primitive Primitive::operator>>(Primitive &primitive) {

		string message = "Bitwise right shift '>>' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Equal to
	Primitive Primitive::operator==(Primitive &primitive) {

		string message = "Equal to '==' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Not equal to
	Primitive Primitive::operator!=(Primitive &primitive) {

		string message = "Not equal to '!=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Greater than
	Primitive Primitive::operator>(Primitive &primitive) {

		string message = "Greater than '>' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Less than
	Primitive Primitive::operator<(Primitive &primitive) {

		string message = "Less than '<' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Greater than or equal to
	Primitive Primitive::operator>=(Primitive &primitive) {

		string message = "Greater than or equal to '>=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Less than or equal to
	Primitive Primitive::operator<=(Primitive &primitive) {

		string message = "Less than or equal to '<=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Addition assignment
	Primitive& Primitive::operator+=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this + primitive);
		} catch (exception e) {

			string message = "Addition assignment '+=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Subtraction assignment
	Primitive& Primitive::operator-=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this - primitive);
		} catch (exception e) {

			string message = "Subtraction assignment '-=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Multiplication assignment
	Primitive& Primitive::operator*=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this * primitive);
		} catch (exception e) {

			string message = "Multiplication assignment '*=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Division assignment
	Primitive& Primitive::operator/=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this / primitive);
		} catch (DivideByZeroException e) {

			throw e;
		} catch (exception e) {

			string message = "Division assignment '/=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Modulation assignment
	Primitive& Primitive::operator%=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this % primitive);
		} catch (DivideByZeroException e) {

			throw e;
		} catch (exception e) {

			string message = "Modulation assignment '%=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Bitwise AND assignment
	Primitive& Primitive::operator&=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this & primitive);
		} catch (exception e) {

			string message = "Bitwise AND assignment '&=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Bitwise OR assignment
	Primitive& Primitive::operator|=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this | primitive);
		} catch (exception e) {

			string message = "Bitwise OR assignment '|=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Bitwise XOR assignment
	Primitive& Primitive::operator^=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this ^ primitive);
		} catch (exception e) {

			string message = "Bitwise XOR assignment '^=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Bitwise shift left assignment
	Primitive& Primitive::operator<<=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this << primitive);
		} catch (exception e) {

			string message = "Bitwise shift left assignment '<<=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Bitwise shift right assignment
	Primitive& Primitive::operator>>=(Primitive &primitive) {

		try {

			*this = (Primitive&)(*this >> primitive);
		} catch (exception e) {

			string message = "Bitwise shift right assignment '>>=' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
			throw new exception(message.c_str());
		}

		return *this;
	}

	// Logical NOT
	Primitive Primitive::operator!() {

		string message = "Logical NOT '!' operation for type " + this->typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Logical AND
	Primitive Primitive::operator&&(Primitive &primitive) {

		string message = "Logical AND '&&' operation between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}

	// Logical OR
	Primitive Primitive::operator||(Primitive &primitive) {

		string message = "Logical OR || between type " + this->typeName() + " and type " + primitive.typeName() + " is not supported";
		throw new exception(message.c_str());
	}
}