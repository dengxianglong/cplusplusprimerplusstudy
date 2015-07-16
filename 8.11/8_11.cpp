#include<iostream>
template<typename T>
void Swap(T &a,T &b);
int main()
{
	using namespace std;
	int i=10;
	int j=20;
	cout<<"i,j="<<i<<j<<endl;
	Swap(i,j);
	cout<<"Now i,j="<<i<<j<<endl;
	double x=24.5;
	double y=81.7;
	cout<<x<<y<<endl;
	Swap(x,y);
	cout<<x<<y<<endl;
	return 0;
}
template<typename T>
void Swap(T &a,T &b)
{
	T temp;
	temp=b;
	b=a;
	a=temp;
}