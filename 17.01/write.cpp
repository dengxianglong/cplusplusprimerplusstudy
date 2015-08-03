#include <iostream>
#include <cstring>

int main()
{
	using namespace std;
	const char * statel = "Florida";
	const char * state2 = "Kansas";
	const char * state3 = "Euphoria";
	int len = std::strlen(state2);
	cout << "Tncreasing loop index:\n";
	int i;
	for ( i = 1; i <= len; i++)
	{
		cout.write(state2, i);
		cout << endl;
	}

	cout << "Dercreasing loop index:\n";
	for ( i = len; i > 0; i--)
		cout.write(state2, i) << endl;
	cout << "Exceeding string length:\n";
	cout.write(state2, len + 5) << endl;
	long val = 560031841;
	cout.write( (char *) &val,sizeof (long));
	return 0;
}