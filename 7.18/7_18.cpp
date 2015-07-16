#include<iostream>
double betsy(int);
double pan(int);
void estimate(int lines,double (*pf)(int));
using namespace std;
int main()
{
	int code;
	cout<<"How many lines of code do you need? ";
	cin>>code;
	cout<<"Here's Besty's emtimate:\n";
	estimate(code,betsy);
	cout<<"Here's pan's estimate:\n";
	estimate(code,pan);
	return 0;
}
double betsy(int lns)
{
	return lns*0.05;
}
double pan(int lns)
{
	return 0.03*lns+0.0004*lns*lns;
}
void estimate(int lines,double (*pf)(int))
{
	cout<<lines<<"lines will take";
	cout<<(*pf)(lines)<<"hours(s)\n";
}