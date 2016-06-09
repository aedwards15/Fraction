#include "Fraction.h"
#include <cassert>
#include <stdexcept>

//Constructs a Fraction object. Will validate (ie check denominator > 0) and reduce fraction (eg 4/8 -> 1/2)
Fraction::Fraction(int numerator, int denominator) {
	numerator_ = numerator;
	denominator_ = denominator;

	validate();
}

Fraction Fraction::operator* (Fraction const& frac) {
	int n, d;

	n = numerator_ * frac.numerator_;
	d = denominator_ * frac.denominator_;

	Fraction temp(n, d);
	return temp;
}

Fraction Fraction::operator/ (Fraction const& frac) {
	int n, d;

	n = numerator_ * frac.denominator_;
	d = denominator_ * frac.numerator_;

	Fraction temp(n, d);
	return temp;
}

Fraction Fraction::operator+ (Fraction const& frac) {
	int n, d;
	d = lcm(denominator_, frac.denominator_);
	n = (numerator_ * (d / denominator_)) + (frac.numerator_ * (d / frac.denominator_));

	Fraction temp(n, d);
	return temp;
}

Fraction Fraction::operator- (Fraction const& frac) {
	int n, d;
	d = lcm(denominator_, frac.denominator_);
	n = (numerator_ * (d / denominator_)) - (frac.numerator_ * (d / frac.denominator_));

	Fraction temp(n, d);
	return temp;
}

//Default defined = works as intended with Fraction = Fraction and with Fraction = { n, d } where n,d are ints.
//Overloaded, though, to have it explicitely defined so as to prevent issues later esp. when pointers are involved.
Fraction Fraction::operator= (Fraction const& frac) {
	numerator_ = frac.numerator_;
	denominator_ = frac.denominator_;

	validate();

	return *this;
}

//We can simply compare the numerator and denominator, without evaluating, because we know that both fractions will be reduced
bool Fraction::operator== (Fraction const& frac) {
	return (numerator_ == frac.numerator_ && denominator_ == frac.denominator_);
}

bool Fraction::operator!= (Fraction const& frac) {
	return (numerator_ != frac.numerator_ || denominator_ != frac.denominator_);
}

//Transform fractions to similar denominators to order fractions by numerator
bool Fraction::operator> (Fraction const& frac) {
	int least = lcm(denominator_, frac.denominator_);
	return (numerator_ * (least / denominator_)) > (frac.numerator_ * (least / frac.denominator_));
}

bool Fraction::operator>= (Fraction const& frac) {
	int least = lcm(denominator_, frac.denominator_);
	return (numerator_ * (least / denominator_)) >= (frac.numerator_ * (least / frac.denominator_));
}

bool Fraction::operator< (Fraction const& frac) {
	int least = lcm(denominator_, frac.denominator_);
	return (numerator_ * (least / denominator_)) < (frac.numerator_ * (least / frac.denominator_));
}

bool Fraction::operator<= (Fraction const& frac) {
	int least = lcm(denominator_, frac.denominator_);
	return (numerator_ * (least / denominator_)) <= (frac.numerator_ * (least / frac.denominator_));
}

//Returns result of fraction as a floating point number
double Fraction::Evaluate() const {
	return ((double)numerator_ / (double)denominator_);
}

//Validates that the denominator is > 0 otherwise throws assert, if in debug, or standard exception, if not; Then reduces fraction
void Fraction::validate() {
	if (denominator_ == 0)
	{
		assert(denominator_ != 0);
		throw std::exception("denominator = 0");
	}

	reduce();
}

//Calculates the Least Common Multiple of to fractions, given their denominators
int Fraction::lcm(int a, int b) const {
	int m, n;

	m = abs(a); 
	n = abs(b);

	while (m != n) {
		if (m < n)
			m = m + a;
		else
			n = n + b;
	}

	return m;
}

//Reduce fraction to lowest form
void Fraction::reduce() {
	int a = abs(numerator_);
	int b = abs(denominator_); //can result in b being negative which may produce unintended result. Make all values positive
	int c = a % b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}

	numerator_ /= b;
	denominator_ /= b;
}