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

			case CHAR:

				this->setFloat(primitive.getChar());
				break;
			case SHORT:

				this->setFloat(primitive.getShort());
				break;
			case INTEGER:

				this->setFloat(primitive.getInt());
				break;
			case LONG:

				this->setFloat(primitive.getLong());
				break;
			case FLOAT:

				this->setFloat(primitive.getFloat());
				break;
			case DOUBLE:

				this->setFloat(primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return *this;
	}

	// Addition
	unique_ptr<Primitive> Float::operator+(Primitive &primitive) {

		unique_ptr<Float> result = make_unique<Float>();

		switch (primitive.getType()) {

			case CHAR:

				result->setFloat(this->getFloat() + primitive.getChar());
				break;
			case SHORT:

				result->setFloat(this->getFloat() + primitive.getShort());
				break;
			case INTEGER:

				result->setFloat(this->getFloat() + primitive.getInt());
				break;
			case LONG:

				result->setFloat(this->getFloat() + primitive.getLong());
				break;
			case FLOAT:

				result->setFloat(this->getFloat() + primitive.getFloat());
				break;
			case DOUBLE:

				result->setFloat(this->getFloat() + primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Subtraction
	unique_ptr<Primitive> Float::operator-(Primitive &primitive) {

		unique_ptr<Float> result = make_unique<Float>();

		switch (primitive.getType()) {

			case CHAR:

				result->setFloat(this->getFloat() - primitive.getChar());
				break;
			case SHORT:

				result->setFloat(this->getFloat() - primitive.getShort());
				break;
			case INTEGER:

				result->setFloat(this->getFloat() - primitive.getInt());
				break;
			case LONG:

				result->setFloat(this->getFloat() - primitive.getLong());
				break;
			case FLOAT:

				result->setFloat(this->getFloat() - primitive.getFloat());
				break;
			case DOUBLE:

				result->setFloat(this->getFloat() - primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Multiplication
	unique_ptr<Primitive> Float::operator*(Primitive &primitive) {

		unique_ptr<Float> result = make_unique<Float>();

		switch (primitive.getType()) {

			case CHAR:

				result->setFloat(this->getFloat() * primitive.getChar());
				break;
			case SHORT:

				result->setFloat(this->getFloat() * primitive.getShort());
				break;
			case INTEGER:

				result->setFloat(this->getFloat() * primitive.getInt());
				break;
			case LONG:

				result->setFloat(this->getFloat() * primitive.getLong());
				break;
			case FLOAT:

				result->setFloat(this->getFloat() * primitive.getFloat());
				break;
			case DOUBLE:

				result->setFloat(this->getFloat() * primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Division
	unique_ptr<Primitive> Float::operator/(Primitive &primitive) {

		unique_ptr<Float> result = make_unique<Float>();

		switch (primitive.getType()) {

			case CHAR:

				result->setFloat(this->getFloat() / primitive.getChar());
				break;
			case SHORT:

				result->setFloat(this->getFloat() / primitive.getShort());
				break;
			case INTEGER:

				result->setFloat(this->getFloat() / primitive.getInt());
				break;
			case LONG:

				result->setFloat(this->getFloat() / primitive.getLong());
				break;
			case FLOAT:

				result->setFloat(this->getFloat() / primitive.getFloat());
				break;
			case DOUBLE:

				result->setFloat(this->getFloat() / primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Prefix incrementation
	Float& Float::operator++() {

		this->data++;

		return *this;
	}

	// Postfix incrementation
	unique_ptr<Primitive> Float::operator++(int) {

		unique_ptr<Float> result = make_unique<Float>(this->getFloat());
		++*this;

		return result;
	}

	// Prefix decrementation
	Float& Float::operator--() {

		this->data--;

		return *this;
	}

	// Postfix decrementation
	unique_ptr<Primitive> Float::operator--(int) {

		unique_ptr<Float> result = make_unique<Float>(this->getFloat());
		--*this;

		return result;
	}

	// Equals
	bool Float::operator==(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getFloat() == primitive.getChar();
				break;
			case SHORT:

				result = this->getFloat() == primitive.getShort();
				break;
			case INTEGER:

				result = this->getFloat() == primitive.getInt();
				break;
			case LONG:

				result = this->getFloat() == primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() == primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() == primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Not equal
	bool Float::operator!=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getFloat() != primitive.getChar();
				break;
			case SHORT:

				result = this->getFloat() != primitive.getShort();
				break;
			case INTEGER:

				result = this->getFloat() != primitive.getInt();
				break;
			case LONG:

				result = this->getFloat() != primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() != primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() != primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Greater than
	bool Float::operator>(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getFloat() > primitive.getChar();
				break;
			case SHORT:

				result = this->getFloat() > primitive.getShort();
				break;
			case INTEGER:

				result = this->getFloat() > primitive.getInt();
				break;
			case LONG:

				result = this->getFloat() > primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() > primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() > primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Less than
	bool Float::operator<(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getFloat() < primitive.getChar();
				break;
			case SHORT:

				result = this->getFloat() < primitive.getShort();
				break;
			case INTEGER:

				result = this->getFloat() < primitive.getInt();
				break;
			case LONG:

				result = this->getFloat() < primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() < primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() < primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Greater than or equal to
	bool Float::operator>=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getFloat() >= primitive.getChar();
				break;
			case SHORT:

				result = this->getFloat() >= primitive.getShort();
				break;
			case INTEGER:

				result = this->getFloat() >= primitive.getInt();
				break;
			case LONG:

				result = this->getFloat() >= primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() >= primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() >= primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Less than or equal to
	bool Float::operator<=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getFloat() <= primitive.getChar();
				break;
			case SHORT:

				result = this->getFloat() <= primitive.getShort();
				break;
			case INTEGER:

				result = this->getFloat() <= primitive.getInt();
				break;
			case LONG:

				result = this->getFloat() <= primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() <= primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getFloat() <= primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}
}