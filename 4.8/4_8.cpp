#include<iostream>
#include<string>
int main()
{
	using namespace std;
	string s1="penguin";
	string s2,s3;
	s2=s1;
	cout<<"s1= "<<s1<<" s2="<<s2<<endl;
	s2="buzzard";
	cout<<"s2="<<s2<<endl;
	s3=s1+s2;
	cout<<s3<<endl;
	s1+=s2;
	cout<<s1<<endl;
	s2+="for a day";
	cout<<s2<<endl;
	return 0;
}