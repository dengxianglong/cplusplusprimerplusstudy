#include<iostream>
#include<cstring>
using namespace std;
char * getname(void);
int main()
{
	char *name;
	name=getname();
	cout<<name<<(int *)name<<endl;
	delete [] name;
	name=getname();
	cout<<name<<(int *)name<<endl;
	delete [] name;
	return 0;
}
char * getname()
{
	char temp[80];
	cout<<"Enter your last name :";
	cin>>temp;
	char* pn=new char[strlen(temp)+1];
	strcpy(pn,temp);
	return pn;
}