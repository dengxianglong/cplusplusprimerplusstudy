#include<iostream>
#include<string>
#include<cstring>
int main()
{
	using namespace std;
	char charr1[20];
	char charr2[20]="jaguar";
	string str1;
	string str2="panther";
	str1=str2;
	strcpy(charr1,charr2);
	str1+=" paste";
	strcat(charr1," juice");
	int len1=str1.size();
	int len2=strlen(charr1);
	cout<<str1<<len1<<endl;
	cout<<charr1<<len2<<endl;
	return 0;
}