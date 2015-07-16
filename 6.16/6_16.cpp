#include<iostream>
#include<fstream>
#include<cstdlib>
const int Size=60;
int main()
{
	using namespace std;
	char filename[Size];
	ifstream inFile;
	cout<<"Enter name of data file:";
	cin.getline(filename,Size);
	inFile.open(filename);
	if(!inFile.is_open())
	{
		cout<<"Coudle not the openthe file: "<<filename<<endl;
		cout<<"Program terminating .\n";
		exit(EXIT_FAILURE);
	}
	double value;
	double sum=0.0;
	int count=0;
	inFile>>value;
	while(inFile.good())
	{
		++count;
		sum+=value;
		inFile>>value;
	}
	if(inFile.eof())
		cout<<"End of file.\n";
	else if(inFile.fail())
		cout<<"Input terminated by data.\n";
	else
		cout<<"unknown reason.\n";
	if(count==0)
		cout<<"No data.\n";
	else
	{
		cout<<"Items read: "<<count<<endl;
		cout<<"sum:"<<sum<<endl;
		cout<<"Average: "<<sum/count<<endl;
	}
	inFile.close();
	return 0;
}