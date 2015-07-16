#include<iostream>
int main()
{
	using std::cout;
	using std::cin;
	char ch;
	int space=0;
	int total=0;
	cin.get(ch);
	while(ch!='.')
	{
		if(ch==' ')
			++space;
		++total;
		cin.get(ch);
	}
	cout<<space<<std::endl<<total;
	return 0;
}