#include<iostream>
const int ar_size=20;
int main()
{
	using namespace std;
	char name[ar_size];
	cin>>name;
	int i=0;
	while(name[i]!='\0')
	{
		cout<<name[i]<<":"<<int(name[i])<<endl;
		i++;
	}
	return 0;
}