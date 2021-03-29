#include <iostream>
#include <cmath>
#include "rational.h"
using namespace std;

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int n, int d)
{
	numerator = n;
	denominator = d;
}

int Rational::getNumerator() const { return this->numerator; }
int Rational::getDenominator() const { return this->denominator; }



Rational::operator double()
{
	double res = denominator + numerator;
	return res / denominator;
}


ostream& operator << (ostream& out, const Rational& a)
{
	if (a.getNumerator() != 0)
	{
		out << a.getNumerator() << "/" << a.getDenominator();
	}
	return out;
}

Rational y1(const Rational& x) {
	return (Rational(2,1) * x + (Rational(13, 10)/ x);
}

Rational operator + (const Rational& a, const Rational& b)
{
	return Rational((a.numerator * b.denominator + b.numerator * a.denominator), (a.denominator * b.denominator));
}

Rational operator - (const Rational& a, const Rational& b)
{
	return Rational((a.numerator * b.denominator - b.numerator * a.denominator), (a.denominator * b.denominator));
}

Rational operator * (const Rational& a, const Rational& b)
{
	return Rational((a.numerator * b.numerator), (a.denominator * b.denominator));
}

Rational operator / (const Rational& a, const Rational& b)
{
	return Rational((a.numerator * b.denominator), (a.denominator * b.numerator));
}

Rational Rational::FromDoubleToRational(double num)
{
	double eps = 0.001;

	for (int i = 1;; i++) {
		double tem = num / (1.0 / i);
		if (fabs(tem - round(tem)) < eps) {
			return Rational(round(tem), i);
			break;
		}
	}
}

void Rational::Cancellation()
{
	if (numerator != 0)
	{
		int m = denominator,
			n = numerator,
			ost = m % n;
		while (ost != 0)
		{
			m = n; n = ost;
			ost = m % n;
		}
		int nod = n;
		if (nod != 1)
		{
			numerator /= nod; denominator /= nod;
		}
	}
}
