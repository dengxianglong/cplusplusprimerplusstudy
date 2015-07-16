#include<iostream>
long double pro(unsigned numbers,unsigned picks);
int main()
{
	using namespace std;
	double total,choices;
	cout<<"Enter the number of picks allowed: \n";
	while((cin>>total>>choices)&&choices<=total)
	{
		cout<<"You have one change in ";
		cout<<pro(total,choices);
		cout<<"of winning .\n";
		cout<<"Next two number (q to quit):";
	}
	cout<<"bye\n";
	return 0;
}
long double pro(unsigned numbers,unsigned picks)
{
	long double result=1.0;
	long double n;
	unsigned p;
	for(n=numbers,p=picks;p>0;n--,p--)
		result=result*n/p;
	return result;
}