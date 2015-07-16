#include<iostream>
#define ZERO 0
#include<climits>
int main()
{
	using namespace std;
	short sam=SHRT_MAX;
	unsigned short sum=sam;
	cout<<"sam :"<<sam<<"sum:"<<sum<<endl;
	sam+=1;
	sum+=1;
	cout<<"sam+1:"<<sam<<"sum+1:"<<sum<<endl;
	sam=ZERO;
	sum=ZERO;
	cout<<sam<<sum<<endl;
	sam-=1;
	sum-=1;
	cout<<"sam-1:"<<sam<<"sum-1:"<<sum<<endl;
	return 0;
}