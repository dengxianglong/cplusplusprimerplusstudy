#include<iostream>
#include<string>
int main()
{
	using namespace std;
	cout<<"Enter aword:";
	string word;
	cin>>word;
	for(int i=word.size()-1;i>=0;i--)
		cout<<word[i];
	return 0;
}