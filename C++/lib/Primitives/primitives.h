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

namespace day {

	class Primitive {

	public:

		enum Type { CHAR, SHORT, INTEGER, LONG, FLOAT, DOUBLE, BOOLEAN };

	protected:

		const Type TYPE;

		/******************************************************************************
		Constructor
		******************************************************************************/
		Primitive(Type type) : TYPE(type) {}

	public:

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
	};
}