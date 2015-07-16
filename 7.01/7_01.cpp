#include<iostream>
void simple();
int main()
{
	using namespace std;
	cout<<"main() will can the simple()\n";
	simple();
	cout<<"main() finish with the simple()\n";
	return 0;
}
void simple()
{
	std::cout<<"I am but a simple\n";
}