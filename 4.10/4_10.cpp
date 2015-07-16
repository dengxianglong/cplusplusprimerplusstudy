#include<iostream>
#include<string>
#include<cstring>
int main()
{
	using namespace std;
	char charr[20];
	string str;
	cout<<strlen(charr)<<endl;
	cout<<str.size()<<endl;
	cin.getline(charr,20);
	cout<<charr<<endl;
	getline(cin,str);
	cout<<str<<endl;
	cout<<strlen(charr)<<endl;
	cout<<str.size()<<endl;
	return 0;
}