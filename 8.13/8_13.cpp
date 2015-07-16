#include<iostream>
template<typename T>
void Swap(T &a,T &b);
struct job
{
	char name[40];
	double salary;
	int floor;
};
template<> void Swap<job>(job &j1,job &j2);
void Show(job &j);
int main()
{
	using namespace std;
	cout.precision(2);
	cout.setf(ios::fixed,ios::floatfield);
	int i=10;
	int j=20;
	cout<<i<<j<<endl;
	Swap(i,j);
	cout<<i<<j<<endl;
	job sue={"asdq adf",73000.60,7};
	job sidney={"Sideny Taffee",78060.72,9};
	Show(sue);
	Show(sidney);
	Swap(sue,sidney);
	Show(sue);
	Show(sidney);
	return 0;
}
template <typename T>
void Swap(T &a,T &b)
{
	T temp;
	temp=a;
	a=b;
	b=temp;
}
template<> void Swap<job>(job &j1,job &j2)
{
	double t1;
	int t2;
	t1=j1.salary;
	j1.salary=j2.salary;
	j2.salary=t1;
	t2=j1.floor;
	j1.floor=j2.floor;
	j2.floor=t2;
}
void Show(job &j)
{
	using namespace std;
	cout<<j.name<<": $"<<j.salary<<"on floor"<<j.floor<<endl;
}
