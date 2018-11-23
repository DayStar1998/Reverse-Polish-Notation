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
#include "boolean.h"
#include "double.h"
#include "float.h"
#include "integer.h"
#include "long.h"
#include "short.h"

namespace day {

	class Double : public Primitive {

	private:

		double data;
	public:

		/******************************************************************************
			Constructor
		******************************************************************************/
		Double(double data = 0) : Primitive(Type::DOUBLE), data(data) {}

		/******************************************************************************
			Function Name: toString

			Des:
				Get the data as a string

			Returns:
				type string, data as a string
		******************************************************************************/
		string toString() override;

		/******************************************************************************
			Function Name: getChar

			Des:
				Get the data as a char

			Returns:
				type char, the data as a char
		******************************************************************************/
		inline char getChar() override {

			return (char)data;
		}

		/******************************************************************************
			Function Name: getShort

			Des:
				Get the data as a short

			Returns:
				type short, the data as a short
		******************************************************************************/
		inline short getShort() override {

			return (short)data;
		}

		/******************************************************************************
			Function Name: getInt

			Des:
				Get the data as an int

			Returns:
				type int, the data as an int
		******************************************************************************/
		inline int getInt() override {

			return (int)data;
		}

		/******************************************************************************
			Function Name: getLong

			Des:
				Get the data as a long

			Returns:
				type long, the data as a long
		******************************************************************************/
		inline long getLong() override {

			return (long)data;
		}

		/******************************************************************************
			Function Name: getFloat

			Des:
				Get the data as a float

			Returns:
				type float, the data as a float
		******************************************************************************/
		inline float getFloat() override {

			return (float)data;
		}

		/******************************************************************************
			Function Name: getDouble

			Des:
				Get the data as a double

			Returns:
				type double, the data as a double
		******************************************************************************/
		inline double getDouble() override {

			return data;
		}

		/******************************************************************************
			Function Name: getBool

			Des:
				Get the data as a bool

			Returns:
				type bool, the data as a bool
		******************************************************************************/
		inline bool getBool() override {

			return data > 0;
		}

		/******************************************************************************
			Function Name: setDouble

			Des:
				Setter for data

			Param:
				data - type double, the new value for the data
		******************************************************************************/
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
			Function Name: assignment

			Des:
				Assign the value of primitive to this

			Params:
				primitive - type Primitive &, the primitive type this is to be
					assigned to

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double& assignment(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator+

			Des:
				Override addition operator

			Params:
				primitive - type Primitive &, the primitive type to be added to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator+(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator-

			Des:
				Override subtraction operator

			Params:
				primitive - type Primitive &, the primitive type to be subtracted by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator-(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator-

			Des:
				Override unary minus operator

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator-() override;

		/******************************************************************************
			Function Name: operator*

			Des:
				Override multiplication operator

			Params:
				primitive - type Primitive &, the primitive type to be multiplied by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator*(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator/

			Des:
				Override division operator

			Params:
				primitive - type Primitive &, the primitive type to be divided by

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator/(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator++

			Des:
				Override prefix increment operator

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double& operator++() override;

		/******************************************************************************
			Function Name: operator++

			Des:
				Override postfix increment operator

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator++(int) override;

		/******************************************************************************
			Function Name: operator--

			Des:
				Override prefix decrement operator

			Returns:
				type Double &, the resulting value
		******************************************************************************/
		Double& operator--() override;

		/******************************************************************************
			Function Name: operator--

			Des:
				Override postfix decrement operator

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator--(int) override;

		/******************************************************************************
			Comparison operators
		******************************************************************************/

		/******************************************************************************
			Function Name: operator==

			Des:
				Override equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator==(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator!=

			Des:
				Override not equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator!=(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator>

			Des:
				Override greater than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator>(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator<

			Des:
				Override less than operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator<(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator>=

			Des:
				Override greater than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator>=(Primitive &primitive) override;

		/******************************************************************************
			Function Name: operator<=

			Des:
				Override less than or equal to operator

			Params:
				primitive - type Primitive &, the primitive type to be compared to

			Returns:
				type shared_ptr<Primitive>, the resulting value
		******************************************************************************/
		shared_ptr<Primitive> operator<=(Primitive &primitive) override;
	};
}