#include<iostream>
const int ArSize=80;
int main()
{
	using namespace std;
	char line[ArSize];
	int spaces=0;
	cout<<"Enter a line of text:\n";
	cin.get(line,ArSize);
	cout<<"Complete:\n"<<line<<endl;
	cout<<"Line thought first:\n";
	for(int i=0;line[i]!='\0';i++)
	{
		cout<<line[i];
		if(line[i]=='.')
			break;
		if(line[i]!=' ')
			continue;
		spaces++;
	}
	cout<<"\n"<<spaces<<endl;
	return 0;
}