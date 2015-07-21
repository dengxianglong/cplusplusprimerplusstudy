#include<iostream>
#include"mytiem0.h"
int main()
{
	using std::cout;
	using std::endl;
	Time planning;
	Time coding(2,40);
	Time fixing(5,55);
	Time total;
	cout<<"Planning time= ";
	planning.show();
	cout<<endl;

	cout<<"Coding time= ";
	coding.show();
	cout<<endl;

	cout<<"fixing tiem= ";
	fixing.show();
	cout<<endl;
	total=coding.Sum(fixing);
	cout<<"coding .sum(fixing)= ";
	total.show();
	cout<<endl;
	return 0;
}