#include <iostream>
#include <string>

#include "reversePolishNotation.h"

using namespace std;
using namespace day;

int main() {

	cout << "Enter equation" << endl;

	string equation;
	ReversePolishNotation rpn;

	getline(cin, equation);

	while (equation != "0") {

		// Recreated each time to avoid old invalid data being left from previous invalid equations
		vector<double> values;
		double result;

		// Surrounded with try-catch to prevent testing from crashing the program while still outputting thrown exceptions
		try {

			string editedEquation = rpn.stripValuesFromEquation(equation.c_str(), equation.length(), values);
			cout << editedEquation << endl;

			editedEquation = rpn.convertInfixToPostFix(editedEquation.c_str(), editedEquation.size());
			cout << editedEquation << endl;

			result = rpn.calcResult(editedEquation.c_str(), editedEquation.size(), values);
			cout << result << endl;
		} catch (exception &e) {

			cerr << e.what() << endl;
		}

		// Get input
		getline(cin, equation);
	};
}