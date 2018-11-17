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
	File Name: character.h

	Author: Matthew Day

	Class Name: Character

	Description:
		Wrapper class for char
******************************************************************************/

#pragma once

#include "primitives.h"

namespace day {

	class Character : public Primitive {

	private:

		int data;

		Character() : Primitive(Type::CHAR) {}
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Character(int data) : Primitive(Type::CHAR), data(data) {}

		inline char getChar() override {

			return data;
		}

		/******************************************************************************
			Arithmetic operators
		******************************************************************************/

		/******************************************************************************
			Function Name: operator+

			Des:
				Override addition operator

			Params:
				primitive - type Primitive &, the primitive type to be added to

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator+(Primitive &primitive);

		/******************************************************************************
			Function Name: operator-

			Des:
				Override subtraction operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator-(Primitive &primitive);

		/******************************************************************************
			Function Name: operator*

			Des:
				Override multiplication operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator*(Primitive &primitive);

		/******************************************************************************
			Function Name: operator/

			Des:
				Override division operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator/(Primitive &primitive);

		/******************************************************************************
			Function Name: operator%

			Des:
				Override modulation operator

			Params:
				primitive - type Primitive &, the primitive type to be modulated by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator%(Primitive &primitive);

		/******************************************************************************
			Function Name: operator++

			Des:
				Override prefix increment operator

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator++();

		/******************************************************************************
			Function Name: operator++

			Des:
				Override postfix increment operator

			Returns:
				type Character, the resulting value
		******************************************************************************/
		Character operator++(int);

		/******************************************************************************
			Function Name: operator--

			Des:
				Override prefix decrement operator

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator--();

		/******************************************************************************
			Function Name: operator--

			Des:
				Override postfix decrement operator

			Returns:
				type Character, the resulting value
		******************************************************************************/
		Character operator--(int);

		/******************************************************************************
			Bitwise operators
		******************************************************************************/

		/******************************************************************************
			Function Name: operator<<

			Des:
				Override left shift operator

			Params:
				primitive - type Primitive &, the primitive type to be shifted by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator<<(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>>

			Des:
				Override right shift operator

			Params:
				primitive - type Primitive &, the primitive type to be shifted by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator>>(Primitive &primitive);

		/******************************************************************************
			Function Name: operator|

			Des:
				Override bitwise OR operator

			Params:
				primitive - type Primitive &, the primitive type to be bitwise OR'd by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator|(Primitive &primitive);

		/******************************************************************************
			Function Name: operator&

			Des:
				Override bitwise AND operator

			Params:
				primitive - type Primitive &, the primitive type to be bitwise AND'd by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator&(Primitive &primitive);

		/******************************************************************************
			Function Name: operator~

			Des:
				Override bitwise NOT operator

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator~();

		/******************************************************************************
			Function Name: operator^

			Des:
				Override bitwise XOR operator

			Params:
				primitive - type Primitive &, the primitive type to be bitwise XOR'd by

			Returns:
				type Character &, the resulting value
		******************************************************************************/
		Character& operator^(Primitive &primitive);

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
		bool operator==(Primitive &primitive);

		/******************************************************************************
			Function Name: operator!=

			Des:
				Override not equal operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		bool operator!=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>

			Des:
				Override greater than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		bool operator>(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<

			Des:
				Override less than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		bool operator<(Primitive &primitive);

		/******************************************************************************
			Function Name: operator>=

			Des:
				Override greater than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		bool operator>=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator<=

			Des:
				Override less than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type bool, the resulting value
		******************************************************************************/
		bool operator<=(Primitive &primitive);
	};
}