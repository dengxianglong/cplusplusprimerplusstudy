#include<iostream>
double cube(double a);
double refcube(double &ra);
int main()
{
	using namespace std;
	double x=3.0;
	cout<<cube(x)<<"= "<<x<<endl;
	double y = refcube(x);
	cout << y << "=" << x << endl;
	cout<<refcube(x)<<"= "<<x<<endl;
	return 0;
}
double cube(double a)
{
	a*=a*a;
	return a;
}
double refcube(double &ra)
{
	ra*=ra*ra;
	return ra;
}