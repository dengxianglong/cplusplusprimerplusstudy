#include<iostream>
int main()
{
	using std::cout;
	using std::cin;
	using std::endl;
	int by;
	cin>>by;
	cout<<by<<endl;
	for(int i=0;i<100;i=i+by)
		cout<<i<<endl;
	return 0;
}