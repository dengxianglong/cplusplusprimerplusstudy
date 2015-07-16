#include<iostream>
void oil(int x);
int main()
{
	using namespace std;
	int texas=31;
	int yaer=2001;
	cout<<"In main"<<texas<<&texas<<endl;
	cout<<"In main"<<yaer<<&yaer<<endl;
	oil(texas);
	cout<<"In main"<<texas<<&texas<<endl;
	cout<<"In main"<<yaer<<&yaer<<endl;
	return 0;
}
void oil(int x)
{
	using namespace std;
	int texas=5;
	cout<<"In oil()"<<texas<<&texas<<endl;
	cout<<"In oil()"<<x<<&x<<endl;
	{
		int texas=113;
		cout<<"In block()"<<texas<<&texas<<endl;
		cout<<"In block()"<<x<<&x<<endl;
	}
	cout<<"post()"<<texas<<&texas;
}