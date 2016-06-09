#ifndef FRACTION_HPP
#define FRACTION_HPP
/*
Creator: Andrew Edwards
Date: 5.16.16
Description: A fraction class that takes in two integer values to represent the numerator and denominator 
	of a fraction. Provides standard overload operators for multiplying, adding, etc fractions; Also, includes
	Getters for accessing private members and an Evaluate function that returns double. 
	Upon construction, will validate fraction (denominator > 0) as well as reduce to lowest form.

Project Outline:
	Implement in C++ a Fraction class that supports the following operations: 
	addition, subtraction, multiplication, division, equality/non-equality, greater than/less than, and display.  
	The project should not take more than a few hours.  
	If you have some ideas that would take longer to implement please write them down for discussion, 
	but there is no need to spend a lot of time on them. 

FUTURE WORK:
	Templates
	support for other data sets (imaginary, rational, w/e)
	Support for *=, +=, etc
	Support for multiply, divide, etc by { n, m }, .Multiply(int, int), etc
	Set precision
	Flag for negative (found in Validate?) --Possible
	Set Numerator/Denominator individual functions --Possible
*/

template<typename T, typename U>
class Fraction
{
public:
	Fraction() {}
	Fraction(T numerator, U denominator) : numerator_(numerator), denominator_(denominator) {}

	Fraction operator* (const Fraction&);
	Fraction operator/ (const Fraction&);
	Fraction operator+ (const Fraction&);
	Fraction operator- (const Fraction&);
	bool operator== (const Fraction&);
	bool operator!= (const Fraction&);
	bool operator> (const Fraction&);
	bool operator>= (const Fraction&);
	bool operator< (const Fraction&);
	bool operator<= (const Fraction&);

	void Display();
	T GetNumerator() { return numerator_; }
	T GetDenominator() { return denominator_; }

private:
	T numerator_;
	U denominator_;

	T lcm(T, U);
	Fraction reduce(const Fraction&);
};

template<typename T, typename U>
Fraction<T, U> Fraction<T, U>::operator* (const Fraction& frac) {
	Fraction<T, U> temp;
	temp.numerator_ = numerator_ * frac.numerator_;
	temp.denominator_ = denominator_ * frac.denominator_;
	return temp;
}

template<typename T, typename U>
Fraction<T, U> Fraction<T, U>::operator/ (const Fraction& frac) {
	Fraction<T, U> temp;
	temp.numerator_ = numerator_ * frac.denominator_;
	temp.denominator_ = denominator_ * frac.numerator_;
	return temp;
}

template<typename T, typename U>
Fraction<T, U> Fraction<T, U>::operator+ (const Fraction& frac) {
	Fraction<T, U> temp;
	T least = lcm(denominator_, frac.denominator_);
	temp.numerator_ = (numerator_ * (least / denominator_)) + (frac.numerator_ * (least / frac.denominator_));
	temp.denominator_ = least;
	return reduce(temp);
}

template<typename T, typename U>
Fraction<T, U> Fraction<T, U>::operator- (const Fraction& frac) {
	Fraction<T, U> temp;
	T least = lcm(denominator_, frac.denominator_);
	temp.numerator_ = (numerator_ * (least / denominator_)) - (frac.numerator_ * (least / frac.denominator_));
	temp.denominator_ = least;
	return reduce(temp);
}

template<typename T, typename U>
bool Fraction<T, U>::operator== (const Fraction& frac) {
	return ((numerator_ / denominator_) == (frac.numerator_ / frac.denominator_));
}

template<typename T, typename U>
void Fraction<T, U>::Display() {
	cout << numerator_ << " / " << denominator_ << endl;
}

template<typename T, typename U>
T Fraction<T, U>::lcm(T a, U b) {
	T m, n;

	m = a;
	n = b;

	while (m != n) {
		if (m < n)
			m = m + a;
		else
			n = n + b;
	}

	return m;
}

template<typename T, typename U>
Fraction<T, U>  Fraction<T, U>::reduce(const Fraction& frac) {
	T a = abs(frac.numerator_);
	U b = abs(frac.denominator_);
	T c = a % b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}

	Fraction<T, U> temp((frac.numerator_ / b), (frac.denominator_ / b));
	return temp;
}

#endif