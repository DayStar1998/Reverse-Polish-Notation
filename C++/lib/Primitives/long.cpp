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

		return to_string(data);
	}

	// Assignment
	Long& Long::operator=(Primitive &primitive) {

		switch (primitive.getType()) {

			case CHAR:

				this->setLong(primitive.getChar());
				break;
			case SHORT:

				this->setLong(primitive.getShort());
				break;
			case INTEGER:

				this->setLong(primitive.getInt());
				break;
			case LONG:

				this->setLong(primitive.getLong());
				break;
			case FLOAT:

				this->setLong(primitive.getFloat());
				break;
			case DOUBLE:

				this->setLong(primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return *this;
	}

	// Addition
	Long Long::operator+(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() + primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() + primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() + primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() + primitive.getLong());
				break;
			case FLOAT:

				result.setLong(this->getLong() + primitive.getFloat());
				break;
			case DOUBLE:

				result.setLong(this->getLong() + primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Subtraction
	Long Long::operator-(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() - primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() - primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() - primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() - primitive.getLong());
				break;
			case FLOAT:

				result.setLong(this->getLong() - primitive.getFloat());
				break;
			case DOUBLE:

				result.setLong(this->getLong() - primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Multiplication
	Long Long::operator*(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() * primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() * primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() * primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() * primitive.getLong());
				break;
			case FLOAT:

				result.setLong(this->getLong() * primitive.getFloat());
				break;
			case DOUBLE:

				result.setLong(this->getLong() * primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Division
	Long Long::operator/(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() / primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() / primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() / primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() / primitive.getLong());
				break;
			case FLOAT:

				result.setLong(this->getLong() / primitive.getFloat());
				break;
			case DOUBLE:

				result.setLong(this->getLong() / primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Modulation
	Long Long::operator%(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() % primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() % primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() % primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() % primitive.getLong());
				break;
			case FLOAT:
				// TODO: Decide whether on not to remove this
				result.setLong(this->getLong() % (int)primitive.getFloat());
				break;
			case DOUBLE:

				result.setLong(this->getLong() % (int)primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Prefix incrementation
	Long& Long::operator++() {

		this->data++;

		return *this;
	}

	// Postfix incrementation
	Long Long::operator++(int) {

		Long result = *this;
		++*this;

		return result;
	}

	// Prefix decrementation
	Long& Long::operator--() {

		this->data--;

		return *this;
	}

	// Postfix decrementation
	Long Long::operator--(int) {

		Long result = *this;
		--*this;

		return result;
	}

	// Bitwise OR
	Long Long::operator|(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() | primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() | primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() | primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() | primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Bitwise AND
	Long Long::operator&(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() & primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() & primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() & primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() & primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Bitwise NOT
	Long Long::operator~() {

		Long result;

		result.setLong(~this->getLong());

		return result;
	}

	// Bitwise XOR
	Long Long::operator^(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() ^ primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() ^ primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() ^ primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() ^ primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Left shift
	Long Long::operator<<(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() << primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() << primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() << primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() << primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Right shift
	Long Long::operator>>(Primitive &primitive) {

		Long result;

		switch (primitive.getType()) {

			case CHAR:

				result.setLong(this->getLong() >> primitive.getChar());
				break;
			case SHORT:

				result.setLong(this->getLong() >> primitive.getShort());
				break;
			case INTEGER:

				result.setLong(this->getLong() >> primitive.getInt());
				break;
			case LONG:

				result.setLong(this->getLong() >> primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Equals
	bool Long::operator==(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getLong() == primitive.getChar();
				break;
			case SHORT:

				result = this->getLong() == primitive.getShort();
				break;
			case INTEGER:

				result = this->getLong() == primitive.getInt();
				break;
			case LONG:

				result = this->getLong() == primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() == primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() == primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Not equal
	bool Long::operator!=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getLong() != primitive.getChar();
				break;
			case SHORT:

				result = this->getLong() != primitive.getShort();
				break;
			case INTEGER:

				result = this->getLong() != primitive.getInt();
				break;
			case LONG:

				result = this->getLong() != primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() != primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() != primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Greater than
	bool Long::operator>(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getLong() > primitive.getChar();
				break;
			case SHORT:

				result = this->getLong() > primitive.getShort();
				break;
			case INTEGER:

				result = this->getLong() > primitive.getInt();
				break;
			case LONG:

				result = this->getLong() > primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() > primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() > primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Less than
	bool Long::operator<(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getLong() < primitive.getChar();
				break;
			case SHORT:

				result = this->getLong() < primitive.getShort();
				break;
			case INTEGER:

				result = this->getLong() < primitive.getInt();
				break;
			case LONG:

				result = this->getLong() < primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() < primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() < primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Greater than or equal to
	bool Long::operator>=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getLong() >= primitive.getChar();
				break;
			case SHORT:

				result = this->getLong() >= primitive.getShort();
				break;
			case INTEGER:

				result = this->getLong() >= primitive.getInt();
				break;
			case LONG:

				result = this->getLong() >= primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() >= primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() >= primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Less than or equal to
	bool Long::operator<=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getLong() <= primitive.getChar();
				break;
			case SHORT:

				result = this->getLong() <= primitive.getShort();
				break;
			case INTEGER:

				result = this->getLong() <= primitive.getInt();
				break;
			case LONG:

				result = this->getLong() <= primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() <= primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getLong() <= primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Addition assignment
	Long& Long::operator+=(Primitive &primitive) {

		*this = (Primitive&)(*this + primitive);

		return *this;
	}

	// Subtraction assignment
	Long& Long::operator-=(Primitive &primitive) {

		*this = (Primitive&)(*this - primitive);

		return *this;
	}

	// Multiplication assignment
	Long& Long::operator*=(Primitive &primitive) {

		*this = (Primitive&)(*this * primitive);

		return *this;
	}

	// Division assignment
	Long& Long::operator/=(Primitive &primitive) {

		*this = (Primitive&)(*this / primitive);

		return *this;
	}

	// Modulation assignment
	Long& Long::operator%=(Primitive &primitive) {

		*this = (Primitive&)(*this % primitive);

		return *this;
	}

	// Addition assignment
	Long& Long::operator+=(Primitive &primitive) {

		*this = (Primitive&)(*this + primitive);

		return *this;
	}

	// Bitwise AND assignment
	Long& Long::operator&=(Primitive &primitive) {

		*this = (Primitive&)(*this & primitive);

		return *this;
	}

	// Bitwise OR assignment
	Long& Long::operator|=(Primitive &primitive) {

		*this = (Primitive&)(*this | primitive);

		return *this;
	}

	// Bitwise XOR assignment
	Long& Long::operator^=(Primitive &primitive) {

		*this = (Primitive&)(*this ^ primitive);

		return *this;
	}

	// Shift left assignment
	Long& Long::operator<<=(Primitive &primitive) {

		*this = (Primitive&)(*this << primitive);

		return *this;
	}

	// Shift right assignment
	Long& Long::operator>>=(Primitive &primitive) {

		*this = (Primitive&)(*this >> primitive);

		return *this;
	}
}