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

#include "Exceptions/divideByZeroException.h"

using std::exception;
using std::string;
using std::to_string;
using std::shared_ptr;
using std::make_shared;

namespace day {

	class Primitive {

	public:

		// TODO: Find way to make this scale better, currently adding anything here requires updating affected overrides in EVERY child class
		enum class Type {

			NULLPTR,
			CHAR,
			SHORT,
			INTEGER,
			LONG,
			FLOAT,
			DOUBLE,
			BOOLEAN
		};

	private:

		// The type of data being stored
		const Type TYPE;

		/*
			Data

			Six possible ways to do this that I am aware of.
				1. List all possible types of data.
						Currently this means a guaranteed size of at least 224 bits per instance. This is before adding
						any types such as long long and it will continue to grow with every new type supported. On the
						upside, it would be the easiest to implement and would be great for performance.
				2. Union of the various types.
						This would mean the size of every instance would always be as large as the largest supported
						type, which is currently long/double of 64 bits. This would lead to issues converting between
						the various integer types and float/double types. I currently don't know how to use unions well
						enough for this to be viable.
				3. Array of unsigned chars.
						This can be set to the exact number of bytes required so there is never an issue with memory
						being wasted. However, the conversion between types could be very costly performance-wise and
						error prone.
				4. Have data be be stored in the specific class using that type.
						This should overall be the best way both performance-wise and memory-wise. Unfortunately, the
						overriding of the assignment '=' operator prevents reassigning a child class to a generic
						variable of type Primitive. I have been unable to find a way to get around this issue which
						makes this method unusable.
				5. Store data as a string.
						It can be easily converted between types, but takes up more space. Specifically, 1 byte for
						the end character and 1 byte for each place in the number. Conversion would also give
						performance overhead. Might be possible to implement data as bytes similar to option 3 which
						would make the string the size of the data type + 1 byte.
				6. Turn Primitive into a template class of type 'T'.
						'T' being the data type. T would be set by the child class. This would be trivial to implement,
						however, this breaks the whole generic type Primitive system where a data structure full of
						multiple different types of Primitive could be created. With this kind of implementation it
						would be far cheaper and easier to just use the data types directly.

				All of these will need to allow for a form of type casting where even if the incorrect data type is
				asked for then it would be converted and returned as that type.

				1 - The memory cost is not worth it and there are better ways to do it.
				6 - With this kind of implementation it would be far cheaper and easier to just use the data types directly.
				4 - Requires use of pointers. The problem is Primitives are meant to be created on the fly and dropped
					without worrying about deleting them from memory. Possible workaround would be using smart pointers

				Option 4 using smart pointers appears to be the best choice at this time
		*/

	public:

		/******************************************************************************
			Constructor
		******************************************************************************/
		Primitive(Type type = Type::NULLPTR) : TYPE(type) {}

		/******************************************************************************
			Function Name: getType

			Des:
				Get the type

			Returns:
				type string, the type
		******************************************************************************/
		inline Type getType();

		/******************************************************************************
			Function Name: typeName

			Des:
				Get the type as a string

			Returns:
				type string, the type as a string
		******************************************************************************/
		string typeName();

		/******************************************************************************
			Function Name: toString

			Des:
				Get the value of the class as a string

			Returns:
				type string, the value as a string
		******************************************************************************/
		virtual string toString() { throw new exception("ToString has not been written yet"); };

		/******************************************************************************
			Function Name: getChar

			Des:
				Get the data as a char

			Returns:
				type char, the data as a char
		******************************************************************************/
		virtual char getChar() {

			string message = "getChar is not available for type " + typeName();
			throw new exception(message.c_str());
		}

		/******************************************************************************
			Function Name: getShort

			Des:
				Get the data as a short

			Returns:
				type short, the data as a short
		******************************************************************************/
		virtual short getShort() {

			string message = "getShort is not available for type " + typeName();
			throw new exception(message.c_str());
		}

		/******************************************************************************
			Function Name: getInt

			Des:
				Get the data as an int

			Returns:
				type int, the data as an int
		******************************************************************************/
		virtual int getInt() {

			string message = "getInt is not available for type " + typeName();
			throw new exception(message.c_str());
		}

		/******************************************************************************
			Function Name: getLong

			Des:
				Get the data as a long

			Returns:
				type long, the data as a long
		******************************************************************************/
		virtual long getLong() {

			string message = "getLong is not available for type " + typeName();
			throw new exception(message.c_str());
		}

		/******************************************************************************
			Function Name: getFloat

			Des:
				Get the data as a float

			Returns:
				type float, the data as a float
		******************************************************************************/
		virtual float getFloat() {

			string message = "getFloat is not available for type " + typeName();
			throw new exception(message.c_str());
		}

		/******************************************************************************
			Function Name: getDouble

			Des:
				Get the data as a double

			Returns:
				type double, the data as a double
		******************************************************************************/
		virtual double getDouble() {

			string message = "getDouble is not available for type " + typeName();
			throw new exception(message.c_str());
		}

		/******************************************************************************
			Function Name: getBool

			Des:
				Get the data as a bool

			Returns:
				type bool, the data as a bool
		******************************************************************************/
		virtual bool getBool() {
			
			string message = "getBool is not available for type " + typeName();
			throw new exception(message.c_str());
		}

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
			Function Name: assignment

			Des:
				Assign the value of primitive to this

			Params:
				primitive - type Primitive &, the primitive type this is to be
					assigned to

			Returns:
				type Primitive &, the resulting value
		******************************************************************************/
		virtual Primitive& assignment(Primitive &primitive);

		/******************************************************************************
			Function Name: operator+

			Des:
				Override addition operator

			Params:
				primitive - type Primitive &, the primitive type to be added to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator+(Primitive &primitive);

		/******************************************************************************
			Function Name: operator-

			Des:
				Override subtraction operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator-(Primitive &primitive);

		/******************************************************************************
			Function Name: operator-

			Des:
				Override unary minus operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator-();

		/******************************************************************************
			Function Name: operator*

			Des:
				Override multiplication operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator*(Primitive &primitive);

		/******************************************************************************
			Function Name: operator/

			Des:
				Override division operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator/(Primitive &primitive);

		/******************************************************************************
			Function Name: operator%

			Des:
				Override modulation operator

			Params:
				primitive - type Primitive &, the primitive type to be modulated by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator%(Primitive &primitive);

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
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator++(int);

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
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator--(int);

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
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator|(Primitive &primitive);

		/******************************************************************************
			Function Name: operator&

			Des:
				Override bitwise AND operator

			Params:
				primitive - type Primitive &, the primitive type to be bitwise AND'd by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator&(Primitive &primitive);

		/******************************************************************************
			Function Name: operator~

			Des:
				Override bitwise NOT operator

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator~();

		/******************************************************************************
			Function Name: operator^

			Des:
				Override bitwise XOR operator

			Params:
				primitive - type Primitive &, the primitive type to be bitwise XOR'd by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator^(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<<

			Des:
				Override left shift operator

			Params:
				primitive - type Primitive &, the primitive type to be shifted by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator<<(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>>

			Des:
				Override right shift operator

			Params:
				primitive - type Primitive &, the primitive type to be shifted by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator>>(Primitive &primitive);

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
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator==(Primitive &primitive);

		/******************************************************************************
			Function Name: operator!=

			Des:
				Override not equal operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator!=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>

			Des:
				Override greater than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator>(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<

			Des:
				Override less than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator<(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>=

			Des:
				Override greater than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator>=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<=

			Des:
				Override less than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator<=(Primitive &primitive);

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
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator!();

		/******************************************************************************
			Function Name: operator&&

			Des:
				Override logical AND operator

			Params:
				primitive - type Primitive &, the value to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator&&(Primitive &primitive);

		/******************************************************************************
			Function Name: operator||

			Des:
				Override logical OR operator

			Params:
				primitive - type Primitive &, the value to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		virtual shared_ptr<Primitive> operator||(Primitive &primitive);
	};
}