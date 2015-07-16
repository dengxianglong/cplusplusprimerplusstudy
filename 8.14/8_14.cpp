#include<iostream>
template<typename T>
void ShowArray(T arr[],int n);
//template<typename T>
//void ShowArray(T *arr[],int n);
struct debts
{
	char name[50];
	double amount;
};
using namespace std;
int main()
{
	int things[6]={13,31,130,131,301,310};
	struct debts mr_E[3]=
	{
		{"adf wef",2400.0},
		{"het fhd",1300.0},
		{"asd gjt",1800.0}
	};
	double *pd[3];
	for(int i=0;i<3;i++)
		pd[i]=&mr_E[i].amount;
	ShowArray(things,6);
	ShowArray(pd,3);
	return 0;
}
template <typename T>
void ShowArray (T arr[],int n)
{
	cout<<"template:A\n";
	for(int i=0;i<n;i++)
		cout<<arr[i]<<' ';
	cout<<endl;
}
/*
template <typename T>
void ShowArray (T *arr[],int n)
{
	cout<<"template:B\n";
	for(int i=0;i<n;i++)
		cout<<*arr[i]<<' ';
	cout<<endl;
}
*/