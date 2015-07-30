#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

void Show(double);
const int LIM = 6;
int main()
{
	using namespace std;
	double arr1[LIM] = {28, 29, 30, 35, 38, 59};
	double arr2[LIM] = {63, 65, 69, 75, 80, 99};
	vector<double> gr2(arr1, arr1 + LIM);
	vector<double> m2(arr2, arr2 + LIM);
	cout .setf(ios_base::fixed);
	cout.precision(1);
	cout << "gr2:\n";
	for_each(gr2.begin(), gr2.end(), Show);
	cout << endl;
	cout << "m2:\n";
	for_each(m2.begin(), m2.end(), Show);
	cout << endl;

	vector<double> sum(LIM);
	transform(gr2.begin(), gr2.end(), m2.begin(), sum.begin(), plus<double>());
	cout << "sum:\n";
	for_each(sum.begin(), sum.end(), Show);
	cout << endl;

	vector<double> prod(LIM);
	transform(gr2.begin(), gr2.end(), prod.begin(),
		bind1st(multiplies<double>(), 2.5));
	cout << "prod:\t";
	for_each(prod.begin(), prod.end(), Show);
	cout << endl;

	return 0;
}

void Show(double v)
{
	std::cout.width(6);
	std::cout<< v << "  ";
}