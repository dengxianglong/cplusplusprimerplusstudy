#include<iostream>
using namespace std;
double warming=0.3;
void update(double dt);
void local();
int main()
{
	cout<<warming<<endl;
	update(0.1);
	cout<<warming<<endl;
	local();
	cout<<warming<<endl;
	return 0;
}