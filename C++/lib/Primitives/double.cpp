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

			case CHAR:

				this->setDouble(primitive.getChar());
				break;
			case SHORT:

				this->setDouble(primitive.getShort());
				break;
			case INTEGER:

				this->setDouble(primitive.getInt());
				break;
			case LONG:

				this->setDouble(primitive.getLong());
				break;
			case FLOAT:

				this->setDouble(primitive.getFloat());
				break;
			case DOUBLE:

				this->setDouble(primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return *this;
	}

	// Addition
	Double Double::operator+(Primitive &primitive) {

		Double result;

		switch (primitive.getType()) {

			case CHAR:

				result.setDouble(this->getDouble() + primitive.getChar());
				break;
			case SHORT:

				result.setDouble(this->getDouble() + primitive.getShort());
				break;
			case INTEGER:

				result.setDouble(this->getDouble() + primitive.getInt());
				break;
			case LONG:

				result.setDouble(this->getDouble() + primitive.getLong());
				break;
			case FLOAT:

				result.setDouble(this->getDouble() + primitive.getFloat());
				break;
			case DOUBLE:

				result.setDouble(this->getDouble() + primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Subtraction
	Double Double::operator-(Primitive &primitive) {

		Double result;

		switch (primitive.getType()) {

			case CHAR:

				result.setDouble(this->getDouble() - primitive.getChar());
				break;
			case SHORT:

				result.setDouble(this->getDouble() - primitive.getShort());
				break;
			case INTEGER:

				result.setDouble(this->getDouble() - primitive.getInt());
				break;
			case LONG:

				result.setDouble(this->getDouble() - primitive.getLong());
				break;
			case FLOAT:

				result.setDouble(this->getDouble() - primitive.getFloat());
				break;
			case DOUBLE:

				result.setDouble(this->getDouble() - primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Multiplication
	Double Double::operator*(Primitive &primitive) {

		Double result;

		switch (primitive.getType()) {

			case CHAR:

				result.setDouble(this->getDouble() * primitive.getChar());
				break;
			case SHORT:

				result.setDouble(this->getDouble() * primitive.getShort());
				break;
			case INTEGER:

				result.setDouble(this->getDouble() * primitive.getInt());
				break;
			case LONG:

				result.setDouble(this->getDouble() * primitive.getLong());
				break;
			case FLOAT:

				result.setDouble(this->getDouble() * primitive.getFloat());
				break;
			case DOUBLE:

				result.setDouble(this->getDouble() * primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Division
	Double Double::operator/(Primitive &primitive) {

		Double result;

		switch (primitive.getType()) {

			case CHAR:

				result.setDouble(this->getDouble() / primitive.getChar());
				break;
			case SHORT:

				result.setDouble(this->getDouble() / primitive.getShort());
				break;
			case INTEGER:

				result.setDouble(this->getDouble() / primitive.getInt());
				break;
			case LONG:

				result.setDouble(this->getDouble() / primitive.getLong());
				break;
			case FLOAT:

				result.setDouble(this->getDouble() / primitive.getFloat());
				break;
			case DOUBLE:

				result.setDouble(this->getDouble() / primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Prefix incrementation
	Double& Double::operator++() {

		this->data++;

		return *this;
	}

	// Postfix incrementation
	Double Double::operator++(int) {

		Double result = *this;
		++*this;

		return result;
	}

	// Prefix decrementation
	Double& Double::operator--() {

		this->data--;

		return *this;
	}

	// Postfix decrementation
	Double Double::operator--(int) {

		Double result = *this;
		--*this;

		return result;
	}

	// Equals
	bool Double::operator==(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getDouble() == primitive.getChar();
				break;
			case SHORT:

				result = this->getDouble() == primitive.getShort();
				break;
			case INTEGER:

				result = this->getDouble() == primitive.getInt();
				break;
			case LONG:

				result = this->getDouble() == primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() == primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() == primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Not equal
	bool Double::operator!=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getDouble() != primitive.getChar();
				break;
			case SHORT:

				result = this->getDouble() != primitive.getShort();
				break;
			case INTEGER:

				result = this->getDouble() != primitive.getInt();
				break;
			case LONG:

				result = this->getDouble() != primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() != primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() != primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Greater than
	bool Double::operator>(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getDouble() > primitive.getChar();
				break;
			case SHORT:

				result = this->getDouble() > primitive.getShort();
				break;
			case INTEGER:

				result = this->getDouble() > primitive.getInt();
				break;
			case LONG:

				result = this->getDouble() > primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() > primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() > primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Less than
	bool Double::operator<(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getDouble() < primitive.getChar();
				break;
			case SHORT:

				result = this->getDouble() < primitive.getShort();
				break;
			case INTEGER:

				result = this->getDouble() < primitive.getInt();
				break;
			case LONG:

				result = this->getDouble() < primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() < primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() < primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Greater than or equal to
	bool Double::operator>=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getDouble() >= primitive.getChar();
				break;
			case SHORT:

				result = this->getDouble() >= primitive.getShort();
				break;
			case INTEGER:

				result = this->getDouble() >= primitive.getInt();
				break;
			case LONG:

				result = this->getDouble() >= primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() >= primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() >= primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Less than or equal to
	bool Double::operator<=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getDouble() <= primitive.getChar();
				break;
			case SHORT:

				result = this->getDouble() <= primitive.getShort();
				break;
			case INTEGER:

				result = this->getDouble() <= primitive.getInt();
				break;
			case LONG:

				result = this->getDouble() <= primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() <= primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getDouble() <= primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Addition assignment
	Double& Double::operator+=(Primitive &primitive) {

		*this = (Primitive&)(*this + primitive);

		return *this;
	}

	// Subtraction assignment
	Double& Double::operator-=(Primitive &primitive) {

		*this = (Primitive&)(*this - primitive);

		return *this;
	}

	// Multiplication assignment
	Double& Double::operator*=(Primitive &primitive) {

		*this = (Primitive&)(*this * primitive);

		return *this;
	}

	// Division assignment
	Double& Double::operator/=(Primitive &primitive) {

		*this = (Primitive&)(*this / primitive);

		return *this;
	}
}