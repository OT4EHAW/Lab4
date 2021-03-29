#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "math.h"
#include <iostream>

using namespace std;

class Rational
{
private:

	int numerator;
	int denominator;


public:
	void Cancellation();
	Rational();
	Rational(int n, int d);
	int getNumerator() const;
	int getDenominator() const;

	Rational FromDoubleToRational(double num);
	friend Rational y1(const Rational& x);
	friend Rational operator + (const Rational& a, const Rational& b);
	friend Rational operator - (const Rational& a, const Rational& b);
	friend Rational operator * (const Rational& a, const Rational& b);
	friend Rational operator / (const Rational& a, const Rational& b);

	operator double();
	friend ostream& operator<<(ostream& out, const Rational& a);
};