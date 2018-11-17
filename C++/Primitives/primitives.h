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

using std::exception;

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

		inline Type getType();
	};

	/******************************************************************************
		Class Name: Character

		Description:
			Wrapper class for chars
	******************************************************************************/
	class Character : public Primitive {

	private:

		char data;
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Character(char data) : Primitive(Type::CHAR), data(data) {}

		inline char getChar() override;
	};

	/******************************************************************************
		Class Name: Integer

		Description:
			Wrapper class for ints
	******************************************************************************/
	class Integer : public Primitive {

	private:

		int data;
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Integer(int data) : Primitive(Type::INTEGER), data(data) {}

		inline int getInt() override;
	};

	/******************************************************************************
		Class Name: Long

		Description:
			Wrapper class for longs
	******************************************************************************/
	class Long : public Primitive {

	private:

		long data;
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Long(long data) : Primitive(Type::LONG), data(data) {}

		inline long getLong() override;
	};

	/******************************************************************************
		Class Name: Float

		Description:
			Wrapper class for floats
	******************************************************************************/
	class Float : public Primitive {

	private:

		float data;
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Float(float data) : Primitive(Type::FLOAT), data(data) {}

		inline float getFloat() override;
	};

	/******************************************************************************
		Class Name: Double

		Description:
			Wrapper class for doubles
	******************************************************************************/
	class Double : public Primitive {

	private:

		double data;
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Double(double data) : Primitive(Type::DOUBLE), data(data) {}

		inline double getDouble() override;
	};

	/******************************************************************************
		Class Name: Boolean

		Description:
			Wrapper class for bools
	******************************************************************************/
	class Boolean : public Primitive {

	private:

		bool data;
	public:

		/******************************************************************************
		Constructor
		******************************************************************************/
		Boolean(bool data) : Primitive(Type::BOOLEAN), data(data) {}

		inline bool getBool() override;
	};
}