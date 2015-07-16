#include<iostream>
extern double warming;
void update(double dt);
void local();
using namespace std;
void update(double dt)
{
	extern double warming;
	warming+=dt;
	cout<<warming;
	cout<<"degrees1.\n";
}
void local()
{
	double warming=0.8;
	cout<<warming;
	cout<<::warming;
	cout<<"degrees2.\n";
}