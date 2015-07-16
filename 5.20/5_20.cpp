#include<iostream>
const int Cities=5;
const int Years=4;
int main()
{
	using namespace std;
	const char *cities[Cities]=
	{
		"City",
		"Town",
		"New",
		"San",
		"Vista"
	};
	int maxtemps[Years][Cities]=
	{
		{96,100,85,67,45},
		{96,78,68,74,86},
		{58,45,65,49,76},
		{45,78,95,49,85}
	};
	for(int city=0;city<Cities;city++)
	{
		cout<<cities[city]<<":\t";
		for(int year=0;year<Years;year++)
			cout<<maxtemps[city][year]<<"\t";
		cout<<endl;
	}
	return 0;
}