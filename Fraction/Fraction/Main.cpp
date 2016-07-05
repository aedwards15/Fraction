#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	double num, den;

	cin >> num;
	cin >> den;

	Fraction<double> test(num, den);

	cout << test.GetNumerator() << " / " << test.GetDenominator() << endl;

	return 0;
}