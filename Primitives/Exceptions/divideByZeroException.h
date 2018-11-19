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
	File Name: divideByZeroException.h

	Author: Matthew Day

	Class Name: DivideByZeroException

	Description:
		Exception to throw for divide by zero errors
******************************************************************************/

#pragma once

#include <stdexcept>

class DivideByZeroException : public std::runtime_error {

public:

	DivideByZeroException() : runtime_error("Division by zero"){}
};