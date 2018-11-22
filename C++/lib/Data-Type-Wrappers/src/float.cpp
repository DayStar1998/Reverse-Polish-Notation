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

		return to_string(getFloat());
	}

	// Assignment
	Float& Float::operator=(Primitive &primitive) {

		this->assignment(primitive);

		return *this;
	}

	// Assignment
	Float& Float::assignment(Primitive &primitive) {

		this->setFloat(primitive.getFloat());

		return *this;
	}

	// Addition
	shared_ptr<Primitive> Float::operator+(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Float>(this->getFloat() + primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Float>(this->getFloat() + primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Float>(this->getFloat() + primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Float>(this->getFloat() + primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getFloat() + primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getFloat() + primitive.getDouble());
				break;
			default:

				result = Primitive::operator+(primitive);
		};

		return result;
	}

	// Subtraction
	shared_ptr<Primitive> Float::operator-(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Float>(this->getFloat() - primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Float>(this->getFloat() - primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Float>(this->getFloat() - primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Float>(this->getFloat() - primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getFloat() - primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getFloat() - primitive.getDouble());
				break;
			default:

				result = Primitive::operator-(primitive);
		};

		return result;
	}

	// Unary minus
	shared_ptr<Primitive> Float::operator-() {

		return make_shared<Float>(-getFloat());
	}

	// Multiplication
	shared_ptr<Primitive> Float::operator*(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Float>(this->getFloat() * primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Float>(this->getFloat() * primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Float>(this->getFloat() * primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Float>(this->getFloat() * primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getFloat() * primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getFloat() * primitive.getDouble());
				break;
			default:

				result = Primitive::operator*(primitive);
		};

		return result;
	}

	// Division
	shared_ptr<Primitive> Float::operator/(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				if (primitive.getChar() == 0)
					throw new DivideByZeroException();

				result = make_shared<Float>(this->getFloat() / primitive.getChar());
				break;
			case Type::SHORT:

				if (primitive.getShort() == 0)
					throw new DivideByZeroException();

				result = make_shared<Float>(this->getFloat() / primitive.getShort());
				break;
			case Type::INTEGER:

				if (primitive.getInt() == 0)
					throw new DivideByZeroException();

				result = make_shared<Float>(this->getFloat() / primitive.getInt());
				break;
			case Type::LONG:

				if (primitive.getLong() == 0)
					throw new DivideByZeroException();

				result = make_shared<Float>(this->getFloat() / primitive.getLong());
				break;
			case Type::FLOAT:

				if (primitive.getFloat() == 0)
					throw new DivideByZeroException();

				result = make_shared<Float>(this->getFloat() / primitive.getFloat());
				break;
			case Type::DOUBLE:

				if (primitive.getDouble() == 0)
					throw new DivideByZeroException();

				result = make_shared<Double>(this->getFloat() / primitive.getDouble());
				break;
			default:

				result = Primitive::operator/(primitive);
		};

		return result;
	}

	// Prefix incrementation
	Float& Float::operator++() {

		setFloat(getFloat() + 1);

		return *this;
	}

	// Postfix incrementation
	shared_ptr<Primitive> Float::operator++(int) {

		shared_ptr<Primitive> result = make_shared<Float>(this->getFloat());
		++*this;

		return result;
	}

	// Prefix decrementation
	Float& Float::operator--() {

		setFloat(getFloat() - 1);

		return *this;
	}

	// Postfix decrementation
	shared_ptr<Primitive> Float::operator--(int) {

		shared_ptr<Primitive> result = make_shared<Float>(this->getFloat());
		--*this;

		return result;
	}

	// Equal to
	shared_ptr<Primitive> Float::operator==(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getFloat() == primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getFloat() == primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getFloat() == primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getFloat() == primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() == primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() == primitive.getDouble());
				break;
			default:

				Primitive::operator==(primitive);
		};

		return result;
	}

	// Not equal to
	shared_ptr<Primitive> Float::operator!=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getFloat() != primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getFloat() != primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getFloat() != primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getFloat() != primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() != primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() != primitive.getDouble());
				break;
			default:

				Primitive::operator!=(primitive);
		};

		return result;
	}

	// Greater than
	shared_ptr<Primitive> Float::operator>(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getFloat() > primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getFloat() > primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getFloat() > primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getFloat() > primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() > primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() > primitive.getDouble());
				break;
			default:

				Primitive::operator>(primitive);
		};

		return result;
	}

	// Less than
	shared_ptr<Primitive> Float::operator<(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getFloat() < primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getFloat() < primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getFloat() < primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getFloat() < primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() < primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() < primitive.getDouble());
				break;
			default:

				Primitive::operator<(primitive);
		};

		return result;
	}

	// Greater than or equal to
	shared_ptr<Primitive> Float::operator>=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getFloat() >= primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getFloat() >= primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getFloat() >= primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getFloat() >= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() >= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() >= primitive.getDouble());
				break;
			default:

				Primitive::operator>=(primitive);
		};

		return result;
	}

	// Less than or equal to
	shared_ptr<Primitive> Float::operator<=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getFloat() <= primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getFloat() <= primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getFloat() <= primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getFloat() <= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() <= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getFloat() <= primitive.getDouble());
				break;
			default:

				Primitive::operator<=(primitive);
		};

		return result;
	}
}