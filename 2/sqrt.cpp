#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	double area;
	cout<<"Enter the floor area, insquare feet,of your home\n";
	cin>>area;
	double side;
	side=sqrt(area);
	cout<<"This is the equivalent of the squre"<<side
		<<"feet to the side."<<endl;
	cout<<"How fascinating!"<<endl;
	return 0;
}