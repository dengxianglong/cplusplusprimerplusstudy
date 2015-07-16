#include<iostream>
#include<fstream>
int main()
{
	using namespace std;
	char mobile[50];
	int year;
	double a_price;
	double d_price;
	ofstream outFile;
	outFile.open("carinfo.txt");
	cout<<"enter the make and model of mobile: ";
	cin.getline(mobile,50);
	cout<<"Enter the moder year: ";
	cin>>year;
	cout<<"Enter the asking price: ";
	cin>>a_price;
	d_price=0.913*a_price;
	cout<<fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout<<"make the model"<<mobile<<endl;
	cout<<"year: "<<year<<endl;
	cout<<"Was asking $:"<<a_price<<endl;
	cout<<"Was asking $:"<<d_price<<endl;
	outFile<<fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile<<"make the model"<<mobile<<endl;
	outFile<<"year: "<<year<<endl;
	outFile<<"Was asking $:"<<a_price<<endl;
	outFile<<"Was asking $:"<<d_price<<endl;
	outFile.close();
	return 0;
}