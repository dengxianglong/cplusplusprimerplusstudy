#include<iostream>
#include"mytime2.h"
int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(4,35);
	Time fixing(2,47);
	Time total;
	Time diff;
	Time adjusted;
	cout<<"Planning time= ";
	planning.show();
	cout<<endl;

	cout<<"Coding time= ";
	coding.show();
	cout<<endl;

	cout<<"fixing tiem= ";
	fixing.show();
	cout<<endl;
	total=coding+(fixing);
	cout<<"coding +(fixing)= ";
	total.show();
	cout<<endl;

	Time morefixing(3,28);
	cout<<"more fixing time=";
	morefixing.show();
	cout<<endl;
	total=morefixing.operator+(total);
	cout<<"morefixing.operator+(total)= ";
	total.show();
	cout<<endl;

	diff=coding-fixing;
	cout<<"Coding-fixing= ";
	diff.show();
	cout<<endl;

	adjusted=total*1.5;
	cout<<"adjusted work time= ";
	adjusted.show();
	cout<<endl;
	return 0;
}