#include<iostream>
int main()
{
	using namespace std;
	char ch='M';
	int i=ch;
	cout<<"The Ascii code for:"<<ch<<" is "<<i<<endl;
	ch=ch+1;
	i=ch;
	cout<<"The Ascii code for:"<<ch<<" is "<<i<<endl;
	cout.put(ch);
	cout.put('!');
	cout<<'\n';
	cout<<"\n";
	return 0;
}