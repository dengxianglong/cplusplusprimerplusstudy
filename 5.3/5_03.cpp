#include<iostream>
int main()
{
	using namespace std;
	int x;
	cout<<(x=100)<<endl;
	cout<<"Now x="<<x<<endl;
	cout<<(x>3)<<endl;
	cout<<(x<3)<<endl;
	cout.setf(ios_base::boolalpha);
	cout<<(x>3)<<endl;
	cout<<(x<3)<<endl;
	return 0;
}