#include <iostream>
#include <string>
#include "queuetp.h"

int main()
{
	using namespace std;

	QueueTP<string> cs(5);
	string temp;

	while (!cs.isfull())
	{
		cout << "Please enter your name. YOu will be "
			<< "server in the order of arrival. \n"
			<< "name: ";
		getline(cin, temp);
		cs.enqueue(temp);
	}
	cout << "The queue is full. Processing begins! \n";

	while (!cs.istempty())
	{
		cs.dequeue(temp);
		cout << "Now processing " << temp << "...\n";
	}
	return 0;
}