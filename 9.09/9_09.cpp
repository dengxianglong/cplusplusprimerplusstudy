#include<iostream>
const int ArSize=10;
void strcount(const char * str);
int main()
{
	using namespace std;
	char input[ArSize];
	char next;
	cout<<"Enter a line:\n";
	cin.get(input,ArSize);
	while(cin)
	{
		cin.get(next);
		while(next!='\n')
			cin.get(next);
		strcount(input);
		cout<<"Enter next line :\n";
		cin.get(input,ArSize);
	}
	cout<<"bye.\n";
	return 0;
}
void strcount(const char * str)
{
	using namespace std;
	static int total=0;
	int count=0;
	cout<<"\""<<str<<"\"contims";
	while(*str++)
		count++;
	total+=count;
	cout<<count<<endl;
	cout<<total<<endl;
}