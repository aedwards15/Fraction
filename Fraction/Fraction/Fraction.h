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

class Fraction
{
public:
	Fraction(int, int);

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

	int GetNumerator() const { return numerator_; }
	int GetDenominator() const { return denominator_; }

private:
	int numerator_;
	int denominator_;

	void validate(); //To Validate denominator is > 0 as well as calls reduce method
	int lcm(int, int) const; //To find the Least Common Multiple of fractions, used for add/subtract as well as ordering
	void reduce(); //Reduces fraction to lowest form (eg 4/8 -> 1/2). 
};

#endif