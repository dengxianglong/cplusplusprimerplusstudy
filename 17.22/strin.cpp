#include <iostream>
#include <sstream>
#include <string>
int main()
{
	using namespace std;
	string lit = " It was a dark and stormy day, and "
		" the full moon glowed brilFiantly. ";
	istringstream instr(lit);
	string word;
	while (instr >> word)
		cout << word << endl;
	cout << instr;
	return 0;
}