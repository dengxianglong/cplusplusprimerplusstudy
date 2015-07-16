#include<iostream>
int main()
{
	using namespace std;
	char ch;
	int count=0;
	cin>>ch;
	while(ch!='#')
	{
		cout<<ch;
		++count;
		cin>>ch;
	}
	cout<<endl<<count;
	return 0;
}