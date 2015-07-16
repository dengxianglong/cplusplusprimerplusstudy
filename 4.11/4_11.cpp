#include<iostream>
struct inflatable
{
	char name[20];
	float volume;
	double price;
};
int main()
{
	using namespace std;
	inflatable guest=
	{
		"dafa sad",
		1.88,
		29.99
	};
	inflatable pal=
	{
		"cfvb zxfd",
		3.12,
		32.99
	};
	cout<<guest.name<<" and "<<pal.name<<endl;
	cout<<guest.price+pal.price<<"\n";
	return 0;
}