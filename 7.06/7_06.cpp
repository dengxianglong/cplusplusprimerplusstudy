#include<iostream>
const int arsize=8;
int sum_arr(int arr[],int n);
int main()
{
	using namespace std;
	int cookies[arsize]={1,2,4,8,13,32,64,128};
	cout<<cookies<<endl;
	cout<<sizeof cookies<<endl;
	int sum=sum_arr(cookies,arsize);
	cout<<sum<<endl;
	sum=sum_arr(cookies,3);
	cout<<sum<<endl;
	sum=sum_arr(cookies+4,4);
	cout<<sum<<endl;
	return 0;
}
int sum_arr(int arr[],int n)
{
	using namespace std;
	int total=0;
	cout<<arr<<endl;
	cout<<sizeof arr<<endl;
	for(int i=0;i<n;i++)
		total=total+arr[i];
	return total;
}