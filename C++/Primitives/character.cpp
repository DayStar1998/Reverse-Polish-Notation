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
	File Name: character.cpp

	Author: Matthew Day

	Description:
		Implementation file for character.h
******************************************************************************/

#include "character.h"

namespace day {

	// Assignment
	Character& Character::operator=(Primitive &primitive) {

		switch (primitive.getType()) {

			case CHAR:

				this->setChar(primitive.getChar());
				break;
			case SHORT:

				this->setChar(primitive.getShort());
				break;
			case INTEGER:

				this->setChar(primitive.getInt());
				break;
			case LONG:

				this->setChar(primitive.getLong());
				break;
			case FLOAT:

				this->setChar(primitive.getFloat());
				break;
			case DOUBLE:

				this->setChar(primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return *this;
	}

	// Addition
	Character Character::operator+(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() + primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() + primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() + primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() + primitive.getLong());
				break;
			case FLOAT:

				result.setChar(this->getChar() + primitive.getFloat());
				break;
			case DOUBLE:

				result.setChar(this->getChar() + primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Subtraction
	Character Character::operator-(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() - primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() - primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() - primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() - primitive.getLong());
				break;
			case FLOAT:

				result.setChar(this->getChar() - primitive.getFloat());
				break;
			case DOUBLE:

				result.setChar(this->getChar() - primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Multiplication
	Character Character::operator*(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() * primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() * primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() * primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() * primitive.getLong());
				break;
			case FLOAT:

				result.setChar(this->getChar() * primitive.getFloat());
				break;
			case DOUBLE:

				result.setChar(this->getChar() * primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Division
	Character Character::operator/(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() / primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() / primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() / primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() / primitive.getLong());
				break;
			case FLOAT:

				result.setChar(this->getChar() / primitive.getFloat());
				break;
			case DOUBLE:

				result.setChar(this->getChar() / primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Modulation
	Character Character::operator%(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() % primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() % primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() % primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() % primitive.getLong());
				break;
			case FLOAT:
				// TODO: Decide whether on not to remove this
				result.setChar(this->getChar() % (int)primitive.getFloat());
				break;
			case DOUBLE:

				result.setChar(this->getChar() % (int)primitive.getDouble());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Prefix incrementation
	Character& Character::operator++() {

		this->data++;

		return *this;
	}

	// Postfix incrementation
	Character Character::operator++(int) {

		Character result = *this;
		++*this;

		return result;
	}

	// Prefix decrementation
	Character& Character::operator--() {

		this->data--;

		return *this;
	}

	// Postfix decrementation
	Character Character::operator--(int) {

		Character result = *this;
		--*this;

		return result;
	}

	// Bitwise OR
	Character Character::operator|(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() | primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() | primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() | primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() | primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Bitwise AND
	Character Character::operator&(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() & primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() & primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() & primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() & primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Bitwise NOT
	Character Character::operator~() {

		Character result;

		result.setChar(~this->getChar());

		return result;
	}

	// Bitwise XOR
	Character Character::operator^(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() ^ primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() ^ primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() ^ primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() ^ primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Left shift
	Character Character::operator<<(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() << primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() << primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() << primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() << primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Right shift
	Character Character::operator>>(Primitive &primitive) {

		Character result;

		switch (primitive.getType()) {

			case CHAR:

				result.setChar(this->getChar() >> primitive.getChar());
				break;
			case SHORT:

				result.setChar(this->getChar() >> primitive.getShort());
				break;
			case INTEGER:

				result.setChar(this->getChar() >> primitive.getInt());
				break;
			case LONG:

				result.setChar(this->getChar() >> primitive.getLong());
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Equals
	bool Character::operator==(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getChar() == primitive.getChar();
				break;
			case SHORT:

				result = this->getChar() == primitive.getShort();
				break;
			case INTEGER:

				result = this->getChar() == primitive.getInt();
				break;
			case LONG:

				result = this->getChar() == primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() == primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() == primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Not equal
	bool Character::operator!=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getChar() != primitive.getChar();
				break;
			case SHORT:

				result = this->getChar() != primitive.getShort();
				break;
			case INTEGER:

				result = this->getChar() != primitive.getInt();
				break;
			case LONG:

				result = this->getChar() != primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() != primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() != primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Greater than
	bool Character::operator>(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getChar() > primitive.getChar();
				break;
			case SHORT:

				result = this->getChar() > primitive.getShort();
				break;
			case INTEGER:

				result = this->getChar() > primitive.getInt();
				break;
			case LONG:

				result = this->getChar() > primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() > primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() > primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Less than
	bool Character::operator<(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getChar() < primitive.getChar();
				break;
			case SHORT:

				result = this->getChar() < primitive.getShort();
				break;
			case INTEGER:

				result = this->getChar() < primitive.getInt();
				break;
			case LONG:

				result = this->getChar() < primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() < primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() < primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Greater than or equal to
	bool Character::operator>=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getChar() >= primitive.getChar();
				break;
			case SHORT:

				result = this->getChar() >= primitive.getShort();
				break;
			case INTEGER:

				result = this->getChar() >= primitive.getInt();
				break;
			case LONG:

				result = this->getChar() >= primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() >= primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() >= primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Less than or equal to
	bool Character::operator<=(Primitive &primitive) {

		bool result;

		switch (primitive.getType()) {

			case CHAR:

				result = this->getChar() <= primitive.getChar();
				break;
			case SHORT:

				result = this->getChar() <= primitive.getShort();
				break;
			case INTEGER:

				result = this->getChar() <= primitive.getInt();
				break;
			case LONG:

				result = this->getChar() <= primitive.getLong();
				break;
			case FLOAT:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() <= primitive.getFloat();
				break;
			case DOUBLE:

				// TODO: Test if this is possible with the issues caused by it's precision
				result = this->getChar() <= primitive.getDouble();
				break;
			default:

				throw new exception("Unsupported operation");
		};

		return result;
	}

	// Addition assignment
	Character& Character::operator+=(Primitive &primitive) {

		*this = (Primitive)(*this + primitive);

		return *this;
	}

	// Subtraction assignment
	Character& Character::operator-=(Primitive &primitive) {

		*this = (Primitive)(*this - primitive);

		return *this;
	}

	// Multiplication assignment
	Character& Character::operator*=(Primitive &primitive) {

		*this = (Primitive)(*this * primitive);

		return *this;
	}

	// Division assignment
	Character& Character::operator/=(Primitive &primitive) {

		*this = (Primitive)(*this / primitive);

		return *this;
	}

	// Modulation assignment
	Character& Character::operator%=(Primitive &primitive) {

		*this = (Primitive)(*this % primitive);

		return *this;
	}

	// Addition assignment
	Character& Character::operator+=(Primitive &primitive) {

		*this = (Primitive)(*this + primitive);

		return *this;
	}

	// Bitwise AND assignment
	Character& Character::operator&=(Primitive &primitive) {

		*this = (Primitive)(*this & primitive);

		return *this;
	}

	// Bitwise OR assignment
	Character& Character::operator|=(Primitive &primitive) {

		*this = (Primitive)(*this | primitive);

		return *this;
	}

	// Bitwise XOR assignment
	Character& Character::operator^=(Primitive &primitive) {

		*this = (Primitive)(*this ^ primitive);

		return *this;
	}

	// Shift left assignment
	Character& Character::operator<<=(Primitive &primitive) {

		*this = (Primitive)(*this << primitive);

		return *this;
	}

	// Shift right assignment
	Character& Character::operator>>=(Primitive &primitive) {

		*this = (Primitive)(*this >> primitive);

		return *this;
	}
}