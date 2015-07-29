#include <iostream>
#include <string>
int main()
{
	using namespace std;
	string empty;
	string small = "bit";
	string larger = "Elephants are a girl's best friend";
	cout << "SIze:\n";
	cout << "\temptty : " << empty.size() << endl;
	cout << "\tsmall: " << small.size() << endl;
	cout << "\tlarger: " << larger.size() << endl;
	cout << "Capacities:\n";
	cout << "\temptty : " << empty.capacity() << endl;
	cout << "\tsmall: " << small.capacity() << endl;
	cout << "\tlarger: " << larger.capacity() << endl;
	empty.reserve(50);
	cout << "Capacity after empty.reserve(50): "
		<< empty.capacity() << endl;
	return 0;
}