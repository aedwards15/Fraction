#ifndef FRACTION_HPP
#define FRACTION_HPP
#include <cassert>
#include <cmath>
#define SMALL 1e-10
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

template<typename T>
class Fraction
{
public:
	Fraction(T, T);

	Fraction operator* (Fraction const&);
	Fraction operator/ (Fraction const&);
	Fraction operator+ (Fraction const&);
	Fraction operator- (Fraction const&);
	Fraction operator= (Fraction const&);
	bool operator== (Fraction const&);
	bool operator!= (Fraction const&);
	bool operator> (Fraction const&);
	bool operator>= (Fraction const&);
	bool operator< (Fraction const&);
	bool operator<= (Fraction const&);

	double Evaluate() const; //Evaluates fraction (ie numerator / denominator)

	T GetNumerator() const { return numerator_; }
	T GetDenominator() const { return denominator_; }

private:
	T numerator_;
	T denominator_;

	void validate(); //To Validate denominator is > 0 as well as calls reduce method
	T lcm(T, T) const; //To find the Least Common Multiple of fractions, used for add/subtract as well as ordering
	void reduce(); //Reduces fraction to lowest form (eg 4/8 -> 1/2). 
};

//Constructs a Fraction object. Will validate (ie check denominator > 0) and reduce fraction (eg 4/8 -> 1/2)
template<typename T>
Fraction<T>::Fraction(T numerator, T denominator) {
	numerator_ = numerator;
	denominator_ = denominator;

	validate();
}

template<typename T>
Fraction<T> Fraction<T>::operator* (const Fraction& frac) {
	Fraction<T> temp;
	temp.numerator_ = numerator_ * frac.numerator_;
	temp.denominator_ = denominator_ * frac.denominator_;
	return temp;
}

template<typename T>
Fraction<T> Fraction<T>::operator/ (const Fraction& frac) {
	Fraction<T> temp;
	temp.numerator_ = numerator_ * frac.denominator_;
	temp.denominator_ = denominator_ * frac.numerator_;
	return temp;
}

template<typename T>
Fraction<T> Fraction<T>::operator+ (const Fraction& frac) {
	Fraction<T> temp;
	T least = lcm(denominator_, frac.denominator_);
	temp.numerator_ = (numerator_ * (least / denominator_)) + (frac.numerator_ * (least / frac.denominator_));
	temp.denominator_ = least;
	return reduce(temp);
}

template<typename T>
Fraction<T> Fraction<T>::operator- (const Fraction& frac) {
	Fraction<T> temp;
	T least = lcm(denominator_, frac.denominator_);
	temp.numerator_ = (numerator_ * (least / denominator_)) - (frac.numerator_ * (least / frac.denominator_));
	temp.denominator_ = least;
	return reduce(temp);
}

template<typename T>
bool Fraction<T>::operator== (const Fraction& frac) {
	return ((numerator_ / denominator_) == (frac.numerator_ / frac.denominator_));
}

//Returns result of fraction as a floating point number
template<typename T>
double Fraction<T>::Evaluate() const {
	return ((double)numerator_ / (double)denominator_);
}

//Validates that the denominator is > 0 otherwise throws assert, if in debug, or standard exception, if not; Then reduces fraction
template<typename T>
void Fraction<T>::validate() {
	if (denominator_ == 0)
	{
		assert(denominator_ != 0);
		throw std::out_of_range("denominator = 0");
	}

	reduce();
}

template<typename T>
T Fraction<T>::lcm(T a, T b) const {
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

template<typename T>
void Fraction<T>::reduce() {
	T a = std::abs(numerator_);
	T b = std::abs(denominator_); //can result in b being negative which may produce unintended result. Make all values positive
	T c = fmod(a,b);

	//Taking an mod of floating point numbers can result in values 'close to' zero w/o being zero
	//I added a 'SMALL' value of 1-e10 to accomodate rounding errors
	while (c != 0 && c > SMALL)
	{
		a = b;
		b = c;
		c = fmod(a,b);
	}

	numerator_ /= b;
	denominator_ /= b;
}

#endif