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
	File Name: long.cpp

	Author: Matthew Day

	Description:
		Implementation file for long.h
******************************************************************************/

#include "long.h"

namespace day {

	string Long::toString() {

		return to_string(getLong());
	}

	// Assignment
	Long& Long::operator=(Primitive &primitive) {

		this->assignment(primitive);

		return *this;
	}

	// Assignment
	Long& Long::assignment(Primitive &primitive) {

		this->setLong(primitive.getLong());

		return *this;
	}

	// Addition
	shared_ptr<Primitive> Long::operator+(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Long>(this->getLong() + primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Long>(this->getLong() + primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Long>(this->getLong() + primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getLong() + primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getLong() + primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getLong() + primitive.getDouble());
				break;
			default:

				result = Primitive::operator+(primitive);
		};

		return result;
	}

	// Subtraction
	shared_ptr<Primitive> Long::operator-(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Long>(this->getLong() - primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Long>(this->getLong() - primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Long>(this->getLong() - primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getLong() - primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getLong() - primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getLong() - primitive.getDouble());
				break;
			default:

				result = Primitive::operator-(primitive);
		};

		return result;
	}

	// Unary minus
	shared_ptr<Primitive> Long::operator-() {

		return make_shared<Long>(-getLong());
	}

	// Multiplication
	shared_ptr<Primitive> Long::operator*(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Long>(this->getLong() * primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Long>(this->getLong() * primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Long>(this->getLong() * primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getLong() * primitive.getLong());
				break;
			case Type::FLOAT:

				result = make_shared<Float>(this->getLong() * primitive.getFloat());
				break;
			case Type::DOUBLE:

				result = make_shared<Double>(this->getLong() * primitive.getDouble());
				break;
			default:

				result = Primitive::operator*(primitive);
		};

		return result;
	}

	// Division
	shared_ptr<Primitive> Long::operator/(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				if (primitive.getChar() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getLong() / primitive.getChar());
				break;
			case Type::SHORT:

				if (primitive.getShort() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getLong() / primitive.getShort());
				break;
			case Type::INTEGER:

				if (primitive.getInt() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getLong() / primitive.getInt());
				break;
			case Type::LONG:

				if (primitive.getLong() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getLong() / primitive.getLong());
				break;
			case Type::FLOAT:

				if (primitive.getFloat() == 0)
					throw new DivideByZeroException();

				result = make_shared<Float>(this->getLong() / primitive.getFloat());
				break;
			case Type::DOUBLE:

				if (primitive.getDouble() == 0)
					throw new DivideByZeroException();

				result = make_shared<Double>(this->getLong() / primitive.getDouble());
				break;
			default:

				result = Primitive::operator/(primitive);
		};

		return result;
	}

	// Modulation
	shared_ptr<Primitive> Long::operator%(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				if (primitive.getChar() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getLong() % primitive.getChar());
				break;
			case Type::SHORT:

				if (primitive.getInt() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getLong() % primitive.getShort());
				break;
			case Type::INTEGER:

				if (primitive.getInt() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getLong() % primitive.getInt());
				break;
			case Type::LONG:

				if (primitive.getLong() == 0)
					throw new DivideByZeroException();

				result = make_shared<Long>(this->getLong() % primitive.getLong());
				break;
			default:

				result = Primitive::operator%(primitive);
		};

		return result;
	}

	// Prefix incrementation
	Long& Long::operator++() {

		setLong(getLong() + 1);

		return *this;
	}

	// Postfix incrementation
	shared_ptr<Primitive> Long::operator++(int) {

		shared_ptr<Primitive> result = make_shared<Long>(this->getLong());
		++*this;

		return result;
	}

	// Prefix decrementation
	Long& Long::operator--() {

		setLong(getLong() - 1);

		return *this;
	}

	// Postfix decrementation
	shared_ptr<Primitive> Long::operator--(int) {

		shared_ptr<Primitive> result = make_shared<Long>(this->getLong());
		--*this;

		return result;
	}

	// Bitwise OR
	shared_ptr<Primitive> Long::operator|(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Long>(this->getLong() | primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Long>(this->getLong() | primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Long>(this->getLong() | primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getLong() | primitive.getLong());
				break;
			default:

				result = Primitive::operator|(primitive);
		};

		return result;
	}

	// Bitwise AND
	shared_ptr<Primitive> Long::operator&(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Long>(this->getLong() & primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Long>(this->getLong() & primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Long>(this->getLong() & primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getLong() & primitive.getLong());
				break;
			default:

				result = Primitive::operator&(primitive);
		};

		return result;
	}

	// Bitwise NOT
	shared_ptr<Primitive> Long::operator~() {

		shared_ptr<Primitive> result = make_shared<Long>();

		result->setLong(~this->getLong());

		return result;
	}

	// Bitwise XOR
	shared_ptr<Primitive> Long::operator^(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Long>(this->getLong() ^ primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Long>(this->getLong() ^ primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Long>(this->getLong() ^ primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getLong() ^ primitive.getLong());
				break;
			default:

				result = Primitive::operator^(primitive);
		};

		return result;
	}

	// Bitwise left shift
	shared_ptr<Primitive> Long::operator<<(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Long>(this->getLong() << primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Long>(this->getLong() << primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Long>(this->getLong() << primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getLong() << primitive.getLong());
				break;
			default:

				result = Primitive::operator<<(primitive);
		};

		return result;
	}

	// Bitwise right shift
	shared_ptr<Primitive> Long::operator>>(Primitive &primitive) {

		shared_ptr<Primitive> result;

		switch (primitive.getType()) {

			case Type::CHAR:

				result = make_shared<Long>(this->getLong() >> primitive.getChar());
				break;
			case Type::SHORT:

				result = make_shared<Long>(this->getLong() >> primitive.getShort());
				break;
			case Type::INTEGER:

				result = make_shared<Long>(this->getLong() >> primitive.getInt());
				break;
			case Type::LONG:

				result = make_shared<Long>(this->getLong() >> primitive.getLong());
				break;
			default:

				result = Primitive::operator>>(primitive);
		};

		return result;
	}

	// Equal to
	shared_ptr<Primitive> Long::operator==(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getLong() == primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getLong() == primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getLong() == primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getLong() == primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() == primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() == primitive.getDouble());
				break;
			default:

				Primitive::operator==(primitive);
		};

		return result;
	}

	// Not equal to
	shared_ptr<Primitive> Long::operator!=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getLong() != primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getLong() != primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getLong() != primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getLong() != primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() != primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() != primitive.getDouble());
				break;
			default:

				Primitive::operator!=(primitive);
		};

		return result;
	}

	// Greater than
	shared_ptr<Primitive> Long::operator>(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getLong() > primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getLong() > primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getLong() > primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getLong() > primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() > primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() > primitive.getDouble());
				break;
			default:

				Primitive::operator>(primitive);
		};

		return result;
	}

	// Less than
	shared_ptr<Primitive> Long::operator<(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getLong() < primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getLong() < primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getLong() < primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getLong() < primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() < primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() < primitive.getDouble());
				break;
			default:

				Primitive::operator<(primitive);
		};

		return result;
	}

	// Greater than or equal to
	shared_ptr<Primitive> Long::operator>=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getLong() >= primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getLong() >= primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getLong() >= primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getLong() >= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() >= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() >= primitive.getDouble());
				break;
			default:

				Primitive::operator>=(primitive);
		};

		return result;
	}

	// Less than or equal to
	shared_ptr<Primitive> Long::operator<=(Primitive &primitive) {

		shared_ptr<Primitive> result = make_shared<Boolean>();

		switch (primitive.getType()) {

			case Type::CHAR:

				result->setBool(this->getLong() <= primitive.getChar());
				break;
			case Type::SHORT:

				result->setBool(this->getLong() <= primitive.getShort());
				break;
			case Type::INTEGER:

				result->setBool(this->getLong() <= primitive.getInt());
				break;
			case Type::LONG:

				result->setBool(this->getLong() <= primitive.getLong());
				break;
			case Type::FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() <= primitive.getFloat());
				break;
			case Type::DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result->setBool(this->getLong() <= primitive.getDouble());
				break;
			default:

				Primitive::operator<=(primitive);
		};

		return result;
	}
}