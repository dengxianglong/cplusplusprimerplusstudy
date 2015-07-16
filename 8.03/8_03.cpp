#include<iostream>
int main()
{
	using namespace std;
	int rats=101;
	int &rodents=rats;
	cout<<rats<<endl;
	cout<<rodents<<endl;
	cout<<&rats<<endl;
	cout<<&rodents<<endl;
	int bunnies=50;
	rodents=bunnies;
	cout<<bunnies<<endl;
	cout<<rats<<endl;
	cout<<rodents<<endl;
	cout<<&bunnies<<endl<<&rodents<<endl;
	char *a="wrent";
	cout<<a<<*(a+1)<<endl;
	return 0;
}