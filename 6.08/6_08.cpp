#include<iostream>
#include<cctype>
int main()
{
	using namespace std;
	cout<<"Enter text for analysis,and type\n";
	char ch;
	int whitespace=0;
	int digits=0;
	int chars=0;
	int punts=0;
	int others=0;
	cin.get(ch);
	while(ch!='@')
	{
		if(isalpha(ch))
			chars++;
		else if(isspace(ch))
			whitespace++;
		else if(isdigit(ch))
			digits++;
		else if(ispunct(ch))
			punts++;
		else others++;
		cin.get(ch);
	}
	cout<<chars<<"letters, ";
	cout<<whitespace<<"whitespace, ";
	cout<<digits<<"digits, ";
	cout<<punts<<endl;
	cout<<others<<endl;
	return 0;
}