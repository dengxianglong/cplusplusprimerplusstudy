#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;
void file_it(ostream &os,double fo,const double fe[],int n);
const int LIMIT=5;
int main()
{
	ofstream fout;
	const char * fn="ep-data.txt";
	fout.open(fn);
	if(!fout.is_open())
	{
		cout<<"Can not open "<<fn<<".bye.\n";
		exit(EXIT_FAILURE);
	}
	double objective;
	cin>>objective;
	double eps[LIMIT];
	cout<<"Enter"<<LIMIT<<"eyepieces: \n";
	for(int i=0;i<LIMIT;i++)
	{
		cout<<"eyepieces #"<<i+1<<": ";
		cin>>eps[i];
	}
	file_it(fout,objective,eps,LIMIT);
	file_it(cout,objective,eps,LIMIT);
	cout<<"Done.\n";
	return 0;
}
void file_it(ostream &os,double fo,const double fe[],int n)
{
	ios_base::fmtflags initial;
	initial=os.setf(ios_base::fixed);
	os.precision(0);
	os<<fo<<"mm\n";
	os.setf(ios::showpoint);
	os.precision(1);
	os.width(12);
	os<<"f.1.eyepiece";
	os.width(15);
	os<<"magnification"<<endl;
	for(int i=0;i<n;i++)
	{
		os.width(12);
		os<<fe[i];
		os.width(15);
		os<<int(fo/fe[i]+0.5)<<endl;
	}
	os.setf(initial);
}