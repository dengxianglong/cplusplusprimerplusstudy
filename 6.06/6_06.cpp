#include<iostream>
const char * qualify[4]=
{
	"aw efweb fss\n",
	"ad sgtr fdhj csg\n",
	"madas asfaq sad",
	"asd fdhh frj",
};
int main()
{
	using namespace std;
	int age;
	cout<<"Enter you age in year";
	cin>>age;
	int index;
	if(age>17&&	age<36)
		index=0;
	if(age>36&&age<50)
		index=1;
	if(age>50&&age<65)
		index=2;
	else
		index=3;
	cout<<qualify[index];
	return 0;
}