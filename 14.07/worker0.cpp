#include "Worker0.h"
#include <iostream>
using namespace std;

Worker::~Worker() {}

void Worker::Set()
{
	cout << "Enter worker's name: ";
	getline(cin,fullname);
	cout << "Enter worker's ID: ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void Worker::Show() const
{
	cout << "Name: " << fullname << "\n";
	cout << "Employee ID: " << id << "\n";
}

void Waiter::Set()
{
	Worker::Set();
	cout << "enter waiter's panache rating: ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void Waiter::Show() const
{
	cout << "Category: waiter\n";
	Worker::Show();
	cout << "Panache rating: " << panache << "\n";
}

char * Singer::pv[] ={"other", "alto", "contralto", 
	"soprano", "bass", "baritone", "tenor"};

void Singer::Set()
{
	Worker::Set();
	cout << "Enter number for singer's vocal range:\n";
	int i;
	for ( i = 0; i < Vtypes; i++)
	{
		cout << i << ": " << pv[i] << "   ";
		if ( i % 4 == 3)
			cout << endl;
	}
	if ( i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >=Vtypes))
		cout << "Please enter avalue >= 0 and < " <<Vtypes << endl;

	while (cin.get() != '\n')
		continue;
}
void Singer::Show() const
{
	cout << "Category: singer\n";
	Worker::Show();
	cout << "Vocal range: " << pv[voice] << endl;
}