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
	File Name: double.h

	Author: Matthew Day

	Class Name: Double

	Description:
		Wrapper class for double
******************************************************************************/

#pragma once

#include "primitives.h"

using std::to_string;

namespace day {

	class Double : public Primitive {

	private:

		double data;

		Double() : Primitive(Type::DOUBLE), data(0) {}
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Double(double data) : Primitive(Type::DOUBLE), data(data) {}

		/******************************************************************************
			Function Name: toString

			Des:
				Get the data as a string

			Returns:
				type string, data as a string
		******************************************************************************/
		string toString() override;

		// Getter
		inline double getDouble() override {

			return data;
		}

		// Setter
		inline void setDouble(double data) override {

			this->data = data;
		}

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
				type Double &, the resulting value
		******************************************************************************/
		Double& operator=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator+

			Des:
				Override addition operator

			Params:
				primitive - type Primitive &, the primitive type to be added to

			Returns:
				type Double, the resulting value
		******************************************************************************/
		Double operator+(Primitive &primitive);

		/******************************************************************************
			Function Name: operator-

			Des:
				Override subtraction operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type Double, the resulting value
		******************************************************************************/
		Double operator-(Primitive &primitive);

		/******************************************************************************
			Function Name: operator*

			Des:
				Override multiplication operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double operator*(Primitive &primitive);

		/******************************************************************************
			Function Name: operator/

			Des:
				Override division operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type Double, the resulting value
		******************************************************************************/
		Double operator/(Primitive &primitive);

		/******************************************************************************
			Function Name: operator++

			Des:
				Override prefix increment operator

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double& operator++();

		/******************************************************************************
			Function Name: operator++

			Des:
				Override postfix increment operator

			Returns:
				type Double, the resulting value
		******************************************************************************/
		Double operator++(int);

		/******************************************************************************
			Function Name: operator--

			Des:
				Override prefix decrement operator

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double& operator--();

		/******************************************************************************
			Function Name: operator--

			Des:
				Override postfix decrement operator

			Returns:
				type Double, the resulting value
		******************************************************************************/
		Double operator--(int);

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
				type Double &, the resulting value
		******************************************************************************/
		Double& operator+=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator-=

			Des:
				Override subtraction assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double& operator-=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator*=

			Des:
				Override multiplication assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double& operator*=(Primitive &primitive);

		/******************************************************************************
			Function Name: operator/=

			Des:
				Override division assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double& operator/=(Primitive &primitive);
	};
}