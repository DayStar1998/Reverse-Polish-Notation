#include <iostream>
#include <string>

#include "reversePolishNotation.h"

using namespace std;

int main() {

	cout << "Enter equation" << endl;

	string equation;
	ReversePolishNotation rpn;

	getline(cin, equation);

	while (equation != "0") {

		// Recreated each time to avoid old invalid data being left from previous invalid equations
		vector<double> values;
		double result;

		string editedEquation = rpn.stripValuesFromEquation(equation.c_str(), equation.length(), values);
		cout << editedEquation << endl;

		editedEquation = rpn.convertInfixToPostFix(editedEquation.c_str(), editedEquation.size());
		cout << editedEquation << endl;

		result = rpn.calcResult(editedEquation.c_str(), editedEquation.size(), values);
		cout << result << endl;

		// Get input
		getline(cin, equation);
	};
}