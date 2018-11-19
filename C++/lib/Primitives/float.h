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
	File Name: float.h

	Author: Matthew Day

	Class Name: Float

	Description:
		Wrapper class for float
******************************************************************************/

#pragma once

#include "primitives.h"
#include "boolean.h"
#include "double.h"
#include "float.h"
#include "integer.h"
#include "long.h"
#include "short.h"

namespace day {

	class Float : public Primitive {

	private:

		float data;
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Float(float data = 0) : Primitive(Type::FLOAT), data(data) {}

		/******************************************************************************
			Function Name: toString

			Des:
				Get the data as a string

			Returns:
				type string, data as a string
		******************************************************************************/
		string toString() override;

		// Getter
		inline float getFloat() override {

			return data;
		}

		// Setter
		inline void setFloat(float data) override {

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
				type Float &, the resulting value
		******************************************************************************/
		Float& operator=(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator+

			Des:
				Override addition operator

			Params:
				primitive - type Primitive &, the primitive type to be added to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator+(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator-

			Des:
				Override subtraction operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator-(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator-

			Des:
				Override unary minus operator

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator-() override;

		/******************************************************************************
			Function Name: operator*

			Des:
				Override multiplication operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator*(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator/

			Des:
				Override division operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator/(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator++

			Des:
				Override prefix increment operator

			Returns:
				type Float &, the resulting value
		******************************************************************************/
		Float& operator++() override;

		/******************************************************************************
			Function Name: operator++

			Des:
				Override postfix increment operator

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator++(int) override;

		/******************************************************************************
			Function Name: operator--

			Des:
				Override prefix decrement operator

			Returns:
				type Float &, the resulting value
		******************************************************************************/
		Float& operator--() override;

		/******************************************************************************
			Function Name: operator--

			Des:
				Override postfix decrement operator

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator--(int) override;

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
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator==(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator!=

			Des:
				Override not equal operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator!=(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator>

			Des:
				Override greater than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator>(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator<

			Des:
				Override less than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator<(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator>=

			Des:
				Override greater than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator>=(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator<=

			Des:
				Override less than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type Primitive, the resulting value
		******************************************************************************/
		Primitive operator<=(Primitive &primitive) override;

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
				type Float &, the resulting value
		******************************************************************************/
		Float& operator+=(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator-=

			Des:
				Override subtraction assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type Float &, the resulting value
		******************************************************************************/
		Float& operator-=(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator*=

			Des:
				Override multiplication assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type Float &, the resulting value
		******************************************************************************/
		Float& operator*=(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator/=

			Des:
				Override division assignment operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type Float &, the resulting value
		******************************************************************************/
		Float& operator/=(Primitive &primitive) override;
	};
}