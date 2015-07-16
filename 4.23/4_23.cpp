#include<iostream>
using namespace std;
struct ant
{
	int year;
};
int main()
{
	ant s1,s2,s3;
	s1.year=1998;
	ant * pa=&s2;
	pa->year=1999;
	ant trio[3];
	trio[0].year=2003;
	cout<<trio->year<<endl;
	ant * arp[3]={&s1,&s2,&s3};
	cout<<arp[1]->year<<endl;
	ant **ppa=arp;
	auto ppb=arp;
	cout<<(*ppa)->year<<endl;
	cout<<(*(ppb+1))->year<<endl;
	return 0;
}