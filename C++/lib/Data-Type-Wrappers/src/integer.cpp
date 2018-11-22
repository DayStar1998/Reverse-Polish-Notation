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
	File Name: integer.cpp

	Author: Matthew Day

	Description:
		Implementation file for integer.h
******************************************************************************/

#include "integer.h"

namespace day {

	string Integer::toString() {

		return to_string(getInt());
	}

	// Assignment
	Integer& Integer::operator=(Primitive &primitive) {

		this->assignment(primitive);

		return *this;
	}

	// Assignment
	Integer& Integer::assignment(Primitive &primitive) {

		this->setInt(primitive.getInt());

		return *this;
	}

	// Addition
	shared_ptr<Primitive> Integer::operator+(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Integer>(this->getInt() + primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Integer>(this->getInt() + primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Integer>(this->getInt() + primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getInt() + primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getInt() + primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getInt() + primitive.getDouble());
				break;
			default:

				result = Primitive::operator+(primitive);
		};

		return result;
	}

	// Subtraction
	shared_ptr<Primitive> Integer::operator-(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Integer>(this->getInt() - primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Integer>(this->getInt() - primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Integer>(this->getInt() - primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getInt() - primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getInt() - primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getInt() - primitive.getDouble());
				break;
			default:

				result = Primitive::operator-(primitive);
		};

		return result;
	}

	// Unary minus
	shared_ptr<Primitive> Integer::operator-() {

		return make_shared<Integer>(-getInt());
	}

	// Multiplication
	shared_ptr<Primitive> Integer::operator*(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Integer>(this->getInt() * primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Integer>(this->getInt() * primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Integer>(this->getInt() * primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getInt() * primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getInt() * primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getInt() * primitive.getDouble());
				break;
			default:

				result = Primitive::operator*(primitive);
		};

		return result;
	}

	// Division
	shared_ptr<Primitive> Integer::operator/(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				if (primitive.getChar() == 0)
					throw new DivideByZeroException();

				result = make_shared<Integer>(this->getInt() / primitive.getChar());
				break;
			case Type::SHORT:

				if (primitive.getShort() == 0)
					throw new DivideByZeroException();

				result = make_shared<Integer>(this->getInt() / primitive.getShort());
				break;
			case Type::INTEGER:

				if (primitive.getInt() == 0)
					throw new DivideByZeroException();

				result = make_shared<Integer>(this->getInt() / primitive.getInt());
				break;
			case Type::LONG:

				if (primitive.getLong() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getInt() / primitive.getLong());
				break;
			case Type::FLOAT:

				if (primitive.getFloat() == 0)
					throw new DivideByZeroException();

				result = make_shared<Float>(this->getInt() / primitive.getFloat());
				break;
			case Type::DOUBLE:

				if (primitive.getDouble() == 0)
					throw new DivideByZeroException();

				result = make_shared<Double>(this->getInt() / primitive.getDouble());
				break;
			default:

				result = Primitive::operator/(primitive);
		};

		return result;
	}

	// Modulation
	shared_ptr<Primitive> Integer::operator%(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				if (primitive.getChar() == 0)
					throw new DivideByZeroException();

				result = make_shared<Integer>(this->getInt() % primitive.getChar());
				break;
			case Type::SHORT:

				if (primitive.getShort() == 0)
					throw new DivideByZeroException();

				result = make_shared<Integer>(this->getInt() % primitive.getShort());
				break;
			case Type::INTEGER:

				if (primitive.getInt() == 0)
					throw new DivideByZeroException();

				result = make_shared<Integer>(this->getInt() % primitive.getInt());
				break;
			case Type::LONG:

				if (primitive.getLong() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getInt() % primitive.getLong());
				break;
			default:

				result = Primitive::operator%(primitive);
		};

		return result;
	}

	// Prefix incrementation
	Integer& Integer::operator++() {

		setInt(getInt() + 1);

		return *this;
	}

	// Postfix incrementation
	shared_ptr<Primitive> Integer::operator++(int) {

		shared_ptr<Primitive> result = make_shared<Integer>(this->getInt());
		++*this;

		return result;
	}

	// Prefix decrementation
	Integer& Integer::operator--() {

		setInt(getInt() - 1);

		return *this;
	}

	// Postfix decrementation
	shared_ptr<Primitive> Integer::operator--(int) {

		shared_ptr<Primitive> result = make_shared<Integer>(this->getInt());
		--*this;

		return result;
	}

	// Bitwise OR
	shared_ptr<Primitive> Integer::operator|(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Integer>(this->getInt() | primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Integer>(this->getInt() | primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Integer>(this->getInt() | primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getInt() | primitive.getLong());
				break;
			default:

				result = Primitive::operator|(primitive);
		};

		return result;
	}

	// Bitwise AND
	shared_ptr<Primitive> Integer::operator&(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Integer>(this->getInt() & primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Integer>(this->getInt() & primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Integer>(this->getInt() & primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getInt() & primitive.getLong());
				break;
			default:

				result = Primitive::operator&(primitive);
		};

		return result;
	}

	// Bitwise NOT
	shared_ptr<Primitive> Integer::operator~() {

		shared_ptr<Primitive> result = make_shared<Integer>();

		result->setInt(~this->getInt());

		return result;
	}

	// Bitwise XOR
	shared_ptr<Primitive> Integer::operator^(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Integer>(this->getInt() ^ primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Integer>(this->getInt() ^ primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Integer>(this->getInt() ^ primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getInt() ^ primitive.getLong());
				break;
			default:

				result = Primitive::operator^(primitive);
		};

		return result;
	}

	// Bitwise left shift
	shared_ptr<Primitive> Integer::operator<<(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Integer>(this->getInt() << primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Integer>(this->getInt() << primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Integer>(this->getInt() << primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getInt() << primitive.getLong());
				break;
			default:

				result = Primitive::operator<<(primitive);
		};

		return result;
	}

	// Bitwise right shift
	shared_ptr<Primitive> Integer::operator>>(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Integer>(this->getInt() >> primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Integer>(this->getInt() >> primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Integer>(this->getInt() >> primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getInt() >> primitive.getLong());
				break;
			default:

				result = Primitive::operator>>(primitive);
		};

		return result;
	}

	// Equal to
	shared_ptr<Primitive> Integer::operator==(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getInt() == primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getInt() == primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getInt() == primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getInt() == primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() == primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() == primitive.getDouble());
				break;
			default:

				Primitive::operator==(primitive);
		};

		return result;
	}

	// Not equal to
	shared_ptr<Primitive> Integer::operator!=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getInt() != primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getInt() != primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getInt() != primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getInt() != primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() != primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() != primitive.getDouble());
				break;
			default:

				Primitive::operator!=(primitive);
		};

		return result;
	}

	// Greater than
	shared_ptr<Primitive> Integer::operator>(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getInt() > primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getInt() > primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getInt() > primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getInt() > primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() > primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() > primitive.getDouble());
				break;
			default:

				Primitive::operator>(primitive);
		};

		return result;
	}

	// Less than
	shared_ptr<Primitive> Integer::operator<(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getInt() < primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getInt() < primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getInt() < primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getInt() < primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() < primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() < primitive.getDouble());
				break;
			default:

				Primitive::operator<(primitive);
		};

		return result;
	}

	// Greater than or equal to
	shared_ptr<Primitive> Integer::operator>=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getInt() >= primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getInt() >= primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getInt() >= primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getInt() >= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() >= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() >= primitive.getDouble());
				break;
			default:

				Primitive::operator>=(primitive);
		};

		return result;
	}

	// Less than or equal to
	shared_ptr<Primitive> Integer::operator<=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getInt() <= primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getInt() <= primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getInt() <= primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getInt() <= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() <= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getInt() <= primitive.getDouble());
				break;
			default:

				Primitive::operator<=(primitive);
		};

		return result;
	}
}