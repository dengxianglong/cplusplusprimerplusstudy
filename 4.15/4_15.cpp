#include<iostream>
int main()
{
	using namespace std;
	int updates=6;
	int *p_updates;
	p_updates=&updates;
	cout<<updates<<"\n"<<*p_updates<<endl;
	cout<<&updates<<p_updates<<endl;
	*p_updates+=1;
	cout<<updates;
	return 0;
}