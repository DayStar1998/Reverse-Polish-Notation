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
	File Name: primitives.h

	Author: Matthew Day

	Class Name: Primitive

	Description:
		Abstract class to act as a base class for wrapping primitive data
			types.
******************************************************************************/

#pragma once

#include <iostream>
#include <string>

using std::exception;
using std::string;
using std::to_string;

namespace day {

	class Primitive {

	public:

		enum Type { NULLPTR, CHAR, SHORT, INTEGER, LONG, FLOAT, DOUBLE, BOOLEAN };

	protected:

		const Type TYPE;

	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Primitive(Type type = NULLPTR) : TYPE(type) {}

		inline Type getType();

		/******************************************************************************
			Function Name: toString

			Des:
				Get the value of the class as a string

			Returns:
				type string, the value as a string
		******************************************************************************/
		virtual string toString() { throw new exception("ToString has not been written yet"); };

		// Default getters
		virtual char getChar() { throw new exception("Char is not available for this type"); }
		virtual short getShort() { throw new exception("Char is not available for this type"); }
		virtual int getInt() { throw new exception("Int is not available for this type"); }
		virtual long getLong() { throw new exception("Long is not available for this type"); }
		virtual float getFloat() { throw new exception("Float is not available for this type"); }
		virtual double getDouble() { throw new exception("Double is not available for this type"); }
		virtual bool getBool() { throw new exception("Bool is not available for this type"); }

		// Default setters
		virtual void setChar(char data) { throw new exception("Char is not available for this type"); }
		virtual void setShort(short data) { throw new exception("Char is not available for this type"); }
		virtual void setInt(int data) { throw new exception("Int is not available for this type"); }
		virtual void setLong(long data) { throw new exception("Long is not available for this type"); }
		virtual void setFloat(float data) { throw new exception("Float is not available for this type"); }
		virtual void setDouble(double data) { throw new exception("Double is not available for this type"); }
		virtual void setBool(bool data) { throw new exception("Bool is not available for this type"); }

		/******************************************************************************
			Arithmetic operators
		******************************************************************************/

		/******************************************************************************
			Function Name: operator=

			Des:
				Override assignment operator

			Params:
				primitive - type Primitive &, the primitive type this is to be
					assigned to

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator+

			Des:
				Override addition operator

			Params:
				primitive - type Primitive &, the primitive type to be added to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator+(Primitive &primitive);

		/******************************************************************************
			Function Name: operator-

			Des:
				Override subtraction operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator-(Primitive &primitive);

		/******************************************************************************
			Function Name: operator*

			Des:
				Override multiplication operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator*(Primitive &primitive);

		/******************************************************************************
			Function Name: operator/

			Des:
				Override division operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator/(Primitive &primitive);

		/******************************************************************************
			Function Name: operator%

			Des:
				Override modulation operator

			Params:
				primitive - type Primitive &, the primitive type to be modulated by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator%(Primitive &primitive);

		/******************************************************************************
			Function Name: operator++

			Des:
				Override prefix increment operator

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator++();

		/******************************************************************************
			Function Name: operator++

			Des:
				Override postfix increment operator

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator++(int);

		/******************************************************************************
			Function Name: operator--

			Des:
				Override prefix decrement operator

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator--();

		/******************************************************************************
			Function Name: operator--

			Des:
				Override postfix decrement operator

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator--(int);

		/******************************************************************************
			Bitwise operators
		******************************************************************************/

		/******************************************************************************
			Function Name: operator|

			Des:
				Override bitwise OR operator

			Params:
				primitive - type Primitive &, the primitive type to be bitwise OR'd by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator|(Primitive &primitive);

		/******************************************************************************
			Function Name: operator&

			Des:
				Override bitwise AND operator

			Params:
				primitive - type Primitive &, the primitive type to be bitwise AND'd by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator&(Primitive &primitive);

		/******************************************************************************
			Function Name: operator~

			Des:
				Override bitwise NOT operator

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator~();

		/******************************************************************************
			Function Name: operator^

			Des:
				Override bitwise XOR operator

			Params:
				primitive - type Primitive &, the primitive type to be bitwise XOR'd by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator^(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<<

			Des:
				Override left shift operator

			Params:
				primitive - type Primitive &, the primitive type to be shifted by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator<<(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>>

			Des:
				Override right shift operator

			Params:
				primitive - type Primitive &, the primitive type to be shifted by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator>>(Primitive &primitive);

		/******************************************************************************
			Comparison operators
		******************************************************************************/

		/******************************************************************************
			Function Name: operator==

			Des:
				Override equals operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		virtual bool operator==(Primitive &primitive);

		/******************************************************************************
			Function Name: operator!=

			Des:
				Override not equal operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		virtual bool operator!=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>

			Des:
				Override greater than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		virtual bool operator>(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<

			Des:
				Override less than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		virtual bool operator<(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>=

			Des:
				Override greater than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		virtual bool operator>=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<=

			Des:
				Override less than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		virtual bool operator<=(Primitive &primitive);

		/******************************************************************************
			Compound assignment operators
		******************************************************************************/

		/******************************************************************************
			Function Name: operator+=

			Des:
				Override addition assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be added to

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator+=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator-=

			Des:
				Override subtraction assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator-=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator*=

			Des:
				Override multiplication assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator*=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator/=

			Des:
				Override division assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator/=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator%=

			Des:
				Override modulation assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be modulated by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator%=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator&=

			Des:
				Override bitwise AND assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be AND'd by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator&=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator|=

			Des:
				Override bitwise OR assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be OR'd by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator|=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator^=

			Des:
				Override bitwise XOR assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be XOR'd by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator^=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<<=

			Des:
				Override shift left assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be shifted left by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator<<=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>>=

			Des:
				Override shift right assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be shifted right by

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& operator>>=(Primitive &primitive);

		/******************************************************************************
			Logic Operators
		******************************************************************************/

		/******************************************************************************
			Function Name: operator!

			Des:
				Override logical NOT operator

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator!();

		/******************************************************************************
			Function Name: operator&&

			Des:
				Override logical AND operator

			Params:
				primitive - type Primitive &, the value to be compared to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator&&(Primitive &primitive);

		/******************************************************************************
			Function Name: operator||

			Des:
				Override logical OR operator

			Params:
				primitive - type Primitive &, the value to be compared to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		virtual Primitive operator||(Primitive &primitive);
	};
}