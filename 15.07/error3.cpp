#include <iostream>

double hmean(double a, double b);
int main()
{
	double x, y, z;

	std::cout << "enter two number: ";
	while (std::cin >> x >> y)
	{
		try
		{
		    z = hmean(x, y);
		}
		catch (const char * s)
		{
			std ::cout << s << std::endl;
			std::cout << "Enter a new pair of number: ";
			continue;
		}
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
		throw "bad hmean () arguments: a = -b not allowed";
	}
	return 2.0 * a * b / (a + b );
}