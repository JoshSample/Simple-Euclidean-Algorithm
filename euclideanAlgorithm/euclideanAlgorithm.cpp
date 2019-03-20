#include <iostream>
using namespace std;

int GreatestCommonDenominator(int a, int b)
{
	if (a == 0)
		return b;
	return GreatestCommonDenominator(b % a, a);
}

void ExtendedGCD(int a, int b)
{
	int x = 0;
	int y = 1;
	int x1 = 1;
	int y1 = 0;
	int q = 0;
	int temp1, temp2, temp3 = 0;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;

	while (b != 0)
	{
		q = a / b;
		temp1 = a % b;
		a = b;
		b = temp1;

		temp2 = x;
		x = x1 - q * x;
		x1 = temp2;

		temp3 = y;
		y = y1 - q * y;
		y1 = temp3;
	}

	cout << "x = " << x1 << endl;
	cout << "y = " << y1 << endl;
}



int main()
{
	int a = 0;
	int b = 0;
	int gcd = 0;
	char repeat;

	do
	{
		cout << "Please enter two natural numbers to find GCD." << endl;
		cout << "Enter a: ";
		cin >> a;
		cout << "Enter b: ";
		cin >> b;
		gcd = GreatestCommonDenominator(a, b);
		cout << "\nGCD(" << a << ", " << b << ")"
			<< " = " << gcd;
		cout << "\nAs a linear combination: " << endl;
		cout << "ax + by = gcd" << endl;
		ExtendedGCD(a, b);

		cout << "Do you want to repeat? <y for yes n for no> ";
		cin >> repeat;
		cout << endl;
	} while (repeat == 'y' || repeat == 'Y');

	return 0;
}