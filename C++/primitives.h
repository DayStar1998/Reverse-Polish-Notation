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

	Class Name: Primitives

	Description:
		Abstract class to act as a base class for wrapping primitive data
			types.
******************************************************************************/

#pragma once

class Primitives {

public:

	enum Type { CHAR, INTEGER, LONG, LONG_LONG, FLOAT, DOUBLE, BOOLEAN };

protected:
	const Type TYPE;

	Primitives(Type type) : TYPE(type) {}

public:
	virtual char getChar();

	virtual int getInt();

	virtual long getLong();

	virtual long long getLongLong();

	virtual float getFloat();

	virtual double getDouble();

	virtual bool getBool();

	inline Type getType();
};

/******************************************************************************
	Class Name: Character

	Description:
		Wrapper class for chars
******************************************************************************/
class Character : public Primitives {

private:

	char data;
public:

	Character(char data) : Primitives(Type::CHAR), data(data) {}

	inline char getChar() override;
};

/******************************************************************************
	Class Name: Integer

	Description:
		Wrapper class for ints
******************************************************************************/
class Integer : public Primitives {

private:

	int data;
public:

	Integer(int data) : Primitives(Type::INTEGER), data(data) {}

	inline int getInt() override;
};

/******************************************************************************
	Class Name: Long

	Description:
		Wrapper class for longs
******************************************************************************/
class Long : public Primitives {

private:

	long data;
public:

	Long(long data) : Primitives(Type::LONG), data(data) {}

	inline long getLong() override;
};

/******************************************************************************
	Class Name: LongLong

	Description:
		Wrapper class for long longs
******************************************************************************/
class LongLong : public Primitives {

private:

	long long data;
public:

	LongLong(long long data) : Primitives(Type::LONG_LONG), data(data) {}

	inline long long getLongLong() override;
};

/******************************************************************************
	Class Name: Float

	Description:
		Wrapper class for floats
******************************************************************************/
class Float : public Primitives {

private:

	float data;
public:

	Float(float data) : Primitives(Type::FLOAT), data(data) {}

	inline float getFloat() override;
};

/******************************************************************************
	Class Name: Double

	Description:
		Wrapper class for doubles
******************************************************************************/
class Double : public Primitives {

private:

	double data;
public:

	Double(double data) : Primitives(Type::DOUBLE), data(data) {}

	inline double getDouble() override;
};

/******************************************************************************
	Class Name: Boolean

	Description:
		Wrapper class for bools
******************************************************************************/
class Boolean : public Primitives {

private:

	bool data;
public:

	Boolean(bool data) : Primitives(Type::BOOLEAN), data(data) {}

	inline bool getBool() override;
};