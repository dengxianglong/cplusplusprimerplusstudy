#include<iostream>
int main()
{
	using namespace std;
	int nights=1001;
	int * pt=new int;
	*pt=1001;
	cout<<nights << &nights <<endl;
	cout<<*pt << pt <<endl;
	double * pd=new double;
	*pd=10000001.0;
	cout<<*pd <<pd <<&pd <<endl;
	cout<<"size of pt" <<sizeof(pt)<<endl;
	cout<<"size os *pt "<<sizeof(*pt)<<endl;
	cout<<"size of pd" <<sizeof pd<<endl;
	cout<<"size os *pd "<<sizeof(*pd)<<endl;
	return 0;
}