#include<iostream>
#include<string>
struct free_
{
	std::string name;
	int made;
	int attempts;
	float percent;
};
void dispaly(const free_ &ft);
void set_pc(free_ &ft);
free_ & accu(free_ &target,const free_ & source);
using namespace std;
int main()
{
	free_ one={"adsa",13,14};
	free_ two={"vbsrc",10,16};
	free_ three={"xcvse",7,9};
	free_ four={"dvav ad",5,9};
	free_ five={"Long Long",6,14};
	free_ team={"Throwgoods",0,0};
	free_ dup;
	set_pc(one);
	dispaly(one);
	accu(accu(team,three),four);
	dispaly(team);
	dup=accu(team,five);
	cout<<"Dispaly team:";
	dispaly(team);
	cout<<"Dup after  assignment:\n";
	dispaly(dup);
	accu(dup,five)=four;
	cout<<"dup after ill\n";
	dispaly(dup);
	return 0;
}
void dispaly(const free_ &ft)
{
	cout<<"name:"<<ft.name<<endl;
	cout<<"made: "<<ft.made<<endl;
	cout<<"Attempt: "<<ft.attempts<<endl;
	cout<<"Percent: "<<ft.percent<<endl;
}
void set_pc(free_ &ft)
{
	if(ft.attempts!=0)
		ft.percent=100.0f*float(ft.made)/float(ft.attempts);
	else
		ft.percent=0;
}
free_ &accu(free_ &target,const free_ &source)
{
	target.attempts+=source.attempts;
	target.made+=source.made;
	set_pc(target);
	return target;
}