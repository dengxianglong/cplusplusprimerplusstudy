#include<iostream>
using namespace std;
const int Max=5;
int filla(double ar[],int limit);
void showa(const double ar[],int n);
void reva(double r,double ar[],int n);
int main()
{
	double pro[Max];
	int size=filla(pro,Max);
	showa(pro,size);
	if(size>0)
	{
		cout<<"enter factor:";
		double factor;
		while(!(cin>>factor))
		{
			cin.clear();
			while(cin.get() !='\n')
				continue;
			cout<<"Please enter a number: ";
		}
		reva(factor,pro,size);
		showa(pro,size);
	}
	cout<<"Done \n";
	cin.get();
	cin.get();
	return 0;
}
int filla(double ar[],int limit)
{
	double temp;
	int i;
	for(i=0;i<limit;i++)
	{
		cout<<"enter value#"<<(i+1)<<": ";
		cin>>temp;
		if(!cin)
		{
			cin.clear();
			while(cin.get()!='\n')
				continue;
			cout<<"Bad input\n";
			break;
		}else if(temp<0)
			break;
		ar[i]=temp;
	}
	return i;
}
void showa(const double ar[],int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Property#"<<(i+1)<<": $";
		cout<<ar[i]<<endl;
	}
}
void reva(double r,double ar[],int n)
{
	for(int i=0;i<n;i++)
		ar[i]*=r;
}