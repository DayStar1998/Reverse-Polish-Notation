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
	File Name: double.cpp

	Author: Matthew Day

	Description:
		Implementation file for double.h
******************************************************************************/

#include "double.h"

namespace day {

	string Double::toString() {

		return to_string(data);
	}

	// Assignment
	Double& Double::operator=(Primitive &primitive) {

		switch (primitive.getType()) {

			case Type::CHAR:

				this->setDouble(primitive.getChar());
				break;
			case Type::SHORT:

				this->setDouble(primitive.getShort());
				break;
			case Type::INTEGER:

				this->setDouble(primitive.getInt());
				break;
			case Type::LONG:

				this->setDouble(primitive.getLong());
				break;
			case Type::FLOAT:

				this->setDouble(primitive.getFloat());
				break;
			case Type::DOUBLE:

				this->setDouble(primitive.getDouble());
				break;
			default:

				Primitive::operator=(primitive);
		};

		return *this;
	}

	// Addition
	Primitive Double::operator+(Primitive &primitive) {

		Double result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setDouble(this->getDouble() + primitive.getChar());
				break;
			case Type::SHORT:

				result.setDouble(this->getDouble() + primitive.getShort());
				break;
			case Type::INTEGER:

				result.setDouble(this->getDouble() + primitive.getInt());
				break;
			case Type::LONG:

				result.setDouble(this->getDouble() + primitive.getLong());
				break;
			case Type::FLOAT:

				result.setDouble(this->getDouble() + primitive.getFloat());
				break;
			case Type::DOUBLE:

				result.setDouble(this->getDouble() + primitive.getDouble());
				break;
			default:

				Primitive::operator+(primitive);
		};

		return result;
	}

	// Subtraction
	Primitive Double::operator-(Primitive &primitive) {

		Double result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setDouble(this->getDouble() - primitive.getChar());
				break;
			case Type::SHORT:

				result.setDouble(this->getDouble() - primitive.getShort());
				break;
			case Type::INTEGER:

				result.setDouble(this->getDouble() - primitive.getInt());
				break;
			case Type::LONG:

				result.setDouble(this->getDouble() - primitive.getLong());
				break;
			case Type::FLOAT:

				result.setDouble(this->getDouble() - primitive.getFloat());
				break;
			case Type::DOUBLE:

				result.setDouble(this->getDouble() - primitive.getDouble());
				break;
			default:

				Primitive::operator-(primitive);
		};

		return result;
	}

	// Unary minus
	Primitive Double::operator-() {

		return Double(-data);
	}

	// Multiplication
	Primitive Double::operator*(Primitive &primitive) {

		Double result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setDouble(this->getDouble() * primitive.getChar());
				break;
			case Type::SHORT:

				result.setDouble(this->getDouble() * primitive.getShort());
				break;
			case Type::INTEGER:

				result.setDouble(this->getDouble() * primitive.getInt());
				break;
			case Type::LONG:

				result.setDouble(this->getDouble() * primitive.getLong());
				break;
			case Type::FLOAT:

				result.setDouble(this->getDouble() * primitive.getFloat());
				break;
			case Type::DOUBLE:

				result.setDouble(this->getDouble() * primitive.getDouble());
				break;
			default:

				Primitive::operator*(primitive);
		};

		return result;
	}

	// Division
	Primitive Double::operator/(Primitive &primitive) {

		Double result;

		switch (primitive.getType()) {

			case Type::CHAR:

				if (primitive.getChar() == 0)
					throw new DivideByZeroException();

				result.setDouble(this->getDouble() / primitive.getChar());
				break;
			case Type::SHORT:

				if (primitive.getShort() == 0)
					throw new DivideByZeroException();

				result.setDouble(this->getDouble() / primitive.getShort());
				break;
			case Type::INTEGER:

				if (primitive.getInt() == 0)
					throw new DivideByZeroException();

				result.setDouble(this->getDouble() / primitive.getInt());
				break;
			case Type::LONG:

				if (primitive.getLong() == 0)
					throw new DivideByZeroException();

				result.setDouble(this->getDouble() / primitive.getLong());
				break;
			case Type::FLOAT:

				if (primitive.getFloat() == 0)
					throw new DivideByZeroException();

				result.setDouble(this->getDouble() / primitive.getFloat());
				break;
			case Type::DOUBLE:

				if (primitive.getDouble() == 0)
					throw new DivideByZeroException();

				result.setDouble(this->getDouble() / primitive.getDouble());
				break;
			default:

				Primitive::operator/(primitive);
		};

		return result;
	}

	// Prefix incrementation
	Double& Double::operator++() {

		this->data++;

		return *this;
	}

	// Postfix incrementation
	Primitive Double::operator++(int) {

		Double result(this->getDouble());
		++*this;

		return result;
	}

	// Prefix decrementation
	Double& Double::operator--() {

		this->data--;

		return *this;
	}

	// Postfix decrementation
	Primitive Double::operator--(int) {

		Double result(this->getDouble());
		--*this;

		return result;
	}

	// Equal to
	Primitive Double::operator==(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getDouble() == primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getDouble() == primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getDouble() == primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getDouble() == primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() == primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() == primitive.getDouble());
				break;
			default:

				Primitive::operator==(primitive);
		};

		return result;
	}

	// Not equal to
	Primitive Double::operator!=(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getDouble() != primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getDouble() != primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getDouble() != primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getDouble() != primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() != primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() != primitive.getDouble());
				break;
			default:

				Primitive::operator!=(primitive);
		};

		return result;
	}

	// Greater than
	Primitive Double::operator>(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getDouble() > primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getDouble() > primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getDouble() > primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getDouble() > primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() > primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() > primitive.getDouble());
				break;
			default:

				Primitive::operator>(primitive);
		};

		return result;
	}

	// Less than
	Primitive Double::operator<(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getDouble() < primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getDouble() < primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getDouble() < primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getDouble() < primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() < primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() < primitive.getDouble());
				break;
			default:

				Primitive::operator<(primitive);
		};

		return result;
	}

	// Greater than or equal to
	Primitive Double::operator>=(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getDouble() >= primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getDouble() >= primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getDouble() >= primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getDouble() >= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() >= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() >= primitive.getDouble());
				break;
			default:

				Primitive::operator>=(primitive);
		};

		return result;
	}

	// Less than or equal to
	Primitive Double::operator<=(Primitive &primitive) {

		Boolean result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result.setBool(this->getDouble() <= primitive.getChar());
				break;
			case Type::SHORT:

				result.setBool(this->getDouble() <= primitive.getShort());
				break;
			case Type::INTEGER:

				result.setBool(this->getDouble() <= primitive.getInt());
				break;
			case Type::LONG:

				result.setBool(this->getDouble() <= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() <= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result.setBool(this->getDouble() <= primitive.getDouble());
				break;
			default:

				Primitive::operator<=(primitive);
		};

		return result;
	}
}