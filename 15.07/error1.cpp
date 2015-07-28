/*
#include <iostream>
#include <cstdlib>
double hmean(double a, double b);
int main()
{
	double x, y, z;

	std::cout << "enter two number: ";
	while (std::cin >> x >> y)
	{
		z = hmean(x, y);
		std::cout << "harmonic mean of " << x << " and " << y
			<< " is " << z << std::endl;
		std::cout << "Enter next set of number < Q TO quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

double hmean(double a, double b)
{
	if ( a == -b)
	{
		std::cout << " Untenable arguments to hmean ()\n";
		std::abort();
	}
	return 2.0 * a * b / (a + b );
}
*/