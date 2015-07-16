#include<iostream>
int main()
{
	using namespace std;
	char ch;
	cin.get(ch);
	while(ch!='.')
	{
		if(ch=='\n')
			cout<<ch;
		else
			cout<<ch+1;
		cin.get(ch);
	}
	return 0;
}