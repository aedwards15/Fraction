#include <iostream>
#include "Fraction.h"

using namespace std;

int main()
{
	Fraction frac(-4, -8);
	Fraction frac2(1, -2);

	frac = frac2;

	cout << frac.GetNumerator() << " / " << frac.GetDenominator() << " = " << frac.Evaluate() << endl;

	frac = frac * frac2;

	double result = frac.Evaluate();

	cout << frac.GetNumerator() << " / " << frac.GetDenominator() << " = " << result << endl;

	int temp;
	cin >> temp;

	return 0;
}