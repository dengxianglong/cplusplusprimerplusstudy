#include<iostream>
using std::cout;
#include"stonewt.h"
void display(const Stonewt &st,int n);
int main()
{
	Stonewt incognito=275;
	Stonewt wolfe(295.7);
	Stonewt taft(21,8);

	cout<<"Then celebrity weight";
	incognito.show_stn();
	cout<<"The detective weight";
	wolfe.show_stn();
	cout<<"The President weight";
	taft.show_lbs();
	incognito=276.8;
	taft=325;
	cout<<"After dinner,the crlrbrity weight";
	incognito.show_stn();
	cout<<"After dinner ,the President weight";
	taft.show_lbs();
	display(taft,2);
	cout<<"The wrestler weight even more.\n";
	display(422,2);
	cout<<"No stone left unearned\n";
	return 0;
}
void display(const Stonewt &st,int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Wow! ";
		st.show_stn();
	}
}