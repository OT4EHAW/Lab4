#include "rational.h"

using namespace std;

double y2(double x2);

int main()
{

	Rational n1(1, 2);
	double x;

	cout << "y(x) = (x2 - 1.3) / (x2 + 1.6) \nEnter value x: " << endl;
	cin >> x;
	Rational res = n1.FromDoubleToRational(y2(x));
	cout << "y(" << x << ") = " << res << endl;
	Rational x1 = n1.FromDoubleToRational(x);
	cout << x1 << endl;
	Rational res2 = y1(x1);
	res2.Cancellation();
	cout << res2 << endl;

	system("pause");
	return 0;
}

double y2(double x2)
{
	return (x2 - 1.3) / (x2 + 1.6);
}