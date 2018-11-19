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
	File Name: float.cpp

	Author: Matthew Day

	Description:
		Implementation file for float.h
******************************************************************************/

#include "float.h"

namespace day {

	string Float::toString() {

		return to_string(data);
	}

	// Assignment
	Float& Float::operator=(Primitive &primitive) {

		switch (primitive.getType()) {

			case Type::CHAR:

				this->setFloat(primitive.getChar());
				break;
			case Type::SHORT:

				this->setFloat(primitive.getShort());
				break;
			case Type::INTEGER:

				this->setFloat(primitive.getInt());
				break;
			case Type::LONG:

				this->setFloat(primitive.getLong());
				break;
			case Type::FLOAT:

				this->setFloat(primitive.getFloat());
				break;
			case Type::DOUBLE:

				this->setFloat(primitive.getDouble());
				break;
			default:

				Primitive::operator=(primitive);
		};

		return *this;
	}

	// Addition
	Primitive Float::operator+(Primitive &primitive) {

		Primitive result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = (Primitive&)Float(this->getFloat() + primitive.getChar());
				break;
			case Type::SHORT:

				result = (Primitive&)Float(this->getFloat() + primitive.getShort());
				break;
			case Type::INTEGER:

				result = (Primitive&)Float(this->getFloat() + primitive.getInt());
				break;
			case Type::LONG:

				result = (Primitive&)Float(this->getFloat() + primitive.getLong());
				break;
			case Type::FLOAT:

				result = (Primitive&)Float(this->getFloat() + primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = (Primitive&)Double(this->getFloat() + primitive.getDouble());
				break;
			default:

				Primitive::operator+(primitive);
		};

		return result;
	}

	// Subtraction
	Primitive Float::operator-(Primitive &primitive) {

		Primitive result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = (Primitive&)Float(this->getFloat() - primitive.getChar());
				break;
			case Type::SHORT:

				result = (Primitive&)Float(this->getFloat() - primitive.getShort());
				break;
			case Type::INTEGER:

				result = (Primitive&)Float(this->getFloat() - primitive.getInt());
				break;
			case Type::LONG:

				result = (Primitive&)Float(this->getFloat() - primitive.getLong());
				break;
			case Type::FLOAT:

				result = (Primitive&)Float(this->getFloat() - primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = (Primitive&)Double(this->getFloat() - primitive.getDouble());
				break;
			default:

				Primitive::operator-(primitive);
		};

		return result;
	}

	// Unary minus
	Primitive Float::operator-() {

		return Float(-data);
	}

	// Multiplication
	Primitive Float::operator*(Primitive &primitive) {

		Primitive result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = (Primitive&)Float(this->getFloat() * primitive.getChar());
				break;
			case Type::SHORT:

				result = (Primitive&)Float(this->getFloat() * primitive.getShort());
				break;
			case Type::INTEGER:

				result = (Primitive&)Float(this->getFloat() * primitive.getInt());
				break;
			case Type::LONG:

				result = (Primitive&)Float(this->getFloat() * primitive.getLong());
				break;
			case Type::FLOAT:

				result = (Primitive&)Float(this->getFloat() * primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = (Primitive&)Double(this->getFloat() * primitive.getDouble());
				break;
			default:

				Primitive::operator*(primitive);
		};

		return result;
	}

	// Division
	Primitive Float::operator/(Primitive &primitive) {

		Primitive result;

		switch (primitive.getType()) {

			case Type::CHAR:

				if (primitive.getChar() == 0)
					throw new DivideByZeroException();

				result = (Primitive&)Float(this->getFloat() / primitive.getChar());
				break;
			case Type::SHORT:

				if (primitive.getShort() == 0)
					throw new DivideByZeroException();

				result = (Primitive&)Float(this->getFloat() / primitive.getShort());
				break;
			case Type::INTEGER:

				if (primitive.getInt() == 0)
					throw new DivideByZeroException();

				result = (Primitive&)Float(this->getFloat() / primitive.getInt());
				break;
			case Type::LONG:

				if (primitive.getLong() == 0)
					throw new DivideByZeroException();

				result = (Primitive&)Float(this->getFloat() / primitive.getLong());
				break;
			case Type::FLOAT:

				if (primitive.getFloat() == 0)
					throw new DivideByZeroException();

				result = (Primitive&)Float(this->getFloat() / primitive.getFloat());
				break;
			case Type::DOUBLE:

				if (primitive.getDouble() == 0)
					throw new DivideByZeroException();

				result = (Primitive&)Double(this->getFloat() / primitive.getDouble());
				break;
			default:

				Primitive::operator/(primitive);
		};

		return result;
	}

	// Prefix incrementation
	Float& Float::operator++() {

		this->data++;

		return *this;
	}

	// Postfix incrementation
	Primitive Float::operator++(int) {

		Float result(this->getFloat());
		++*this;

		return result;
	}

	// Prefix decrementation
	Float& Float::operator--() {

		this->data--;

		return *this;
	}

	// Postfix decrementation
	Primitive Float::operator--(int) {

		Float result(this->getFloat());
		--*this;

		return result;
	}

	// Equal to
	Primitive Float::operator==(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getFloat() == primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getFloat() == primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getFloat() == primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getFloat() == primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() == primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() == primitive.getDouble());
				break;
			default:

				Primitive::operator==(primitive);
		};

		return result;
	}

	// Not equal to
	Primitive Float::operator!=(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getFloat() != primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getFloat() != primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getFloat() != primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getFloat() != primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() != primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() != primitive.getDouble());
				break;
			default:

				Primitive::operator!=(primitive);
		};

		return result;
	}

	// Greater than
	Primitive Float::operator>(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getFloat() > primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getFloat() > primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getFloat() > primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getFloat() > primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() > primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() > primitive.getDouble());
				break;
			default:

				Primitive::operator>(primitive);
		};

		return result;
	}

	// Less than
	Primitive Float::operator<(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getFloat() < primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getFloat() < primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getFloat() < primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getFloat() < primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() < primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() < primitive.getDouble());
				break;
			default:

				Primitive::operator<(primitive);
		};

		return result;
	}

	// Greater than or equal to
	Primitive Float::operator>=(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getFloat() >= primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getFloat() >= primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getFloat() >= primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getFloat() >= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() >= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() >= primitive.getDouble());
				break;
			default:

				Primitive::operator>=(primitive);
		};

		return result;
	}

	// Less than or equal to
	Primitive Float::operator<=(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getFloat() <= primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getFloat() <= primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getFloat() <= primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getFloat() <= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() <= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getFloat() <= primitive.getDouble());
				break;
			default:

				Primitive::operator<=(primitive);
		};

		return result;
	}
}