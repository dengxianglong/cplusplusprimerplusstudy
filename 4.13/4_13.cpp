#include<iostream>
struct inflatable
{
	char name[20];
	float volumn;
	double price;
};
int main()
{
	using namespace std;
	inflatable guest[2]=
	{
		{"bambi",0.5,21.99},
		{"Godzilla",2000,565.99}
	};
	cout<<guest[0].name<<guest[1].name<<endl;
	cout<<guest[0].price+guest[1].price<<endl;
	return 0;
}