#include<iostream>
const int ar_size=16;
int main()
{
	long long fact[ar_size];
	fact[1]=fact[0]=1LL;
	for(int i=2;i<ar_size;i++)
		fact[i]=i*fact[i-1];
	for(int i=0;i<ar_size;i++)
		std::cout<<i<<"!= "<<fact[i]<<std::endl;
	return 0;
}