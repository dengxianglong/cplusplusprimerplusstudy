/*
#include <iostream>
#include <cfloat>
bool hmean(double a, double b, double * ans);
int main()
{
	double x, y, z;

	std::cout << "enter two number: ";
	while (std::cin >> x >> y)
	{
		if (hmean(x, y, &z))
		    std::cout << "harmonic mean of " << x << " and " << y
			  << " is " << z << std::endl;
		else
			std::cout << "One value should not be the nagative "
			<< "Of the other - try again. \n";
		std::cout << "Enter next set of number < Q TO quit>: ";
	}
	std::cout << "Bye!\n";
	return 0;
}

bool hmean(double a, double b, double * ans)
{
	if ( a == -b)
	{
		* ans = DBL_MAX;
		return false;
	}
	else
	{
		* ans = 2.0 * a * b / (a + b );
	    return true;
	}
}
*/