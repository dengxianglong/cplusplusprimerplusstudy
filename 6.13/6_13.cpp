#include<iostream>
const int Max=5;
int main()
{
	using namespace std;
	double fish[Max];
	cout<<"fish #1:";
	int i=0;
	while(i<Max&&cin>>fish[i])
	{
		if(++i<Max)
			cout<<"fish #"<<i+1<<": ";}
		double total=0.0;
		for(int j=0;j<i;j++)
			total+=fish[j];
		if(i==0)
			cout<<"No fish\n";
		else
			cout<<total/i<<"=average of"<<i<<"fish\n";
		return 0;
}