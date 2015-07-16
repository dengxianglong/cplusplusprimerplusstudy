#include<iostream>
int main()
{
	using namespace std;
	int x=2;
	{
		cout<<x<<endl;
		int x=200;
		cout<<x<<endl;
	}
	cout<<x<<endl;
	return 0;
}