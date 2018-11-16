#include "stringUtils.h"

namespace day {

	double getNumber(const char *data, int length, int start, int &end) {

		double result;
		string number = "";
		int pos = start;

		// Skip the negative sign to avoid checking if the sign is relative to this number or just a minus sign
		if (data[start] == '-') {

			number.push_back('-');
			pos++;
		}

		// Avoid having to increment with every iteration to prevent it from not being set if the loop runs until equal to length
		end = length - 1;

		for (int i = pos; i < length; i++) {

			// Check if current char is a number or a decimal point
			if (isdigit(data[i]) || data[i] == '.')
				number.push_back(data[i]);
			else {

				end = i - 1;
				break;
			}
		}

		// Convert to double
		result = stod(number);

		return result;
	}
}