#include <iostream>
#include <exception>

int main()
{
	using namespace std;
	cin.exceptions(ios_base::failbit);
	cout << "Enter number: ";
	int sum = 0;
	int input;
	try{
		while (cin >> input)
		{
			sum += input;
		}
	}catch(ios_base::failure & bf)
	{
		cout << bf.what() << endl;
		cout << "O! the horror!\n";
	}

	cout << "Last value enter = " << input << endl;
	cout << "Sum = " << sum << endl;
	return 0;
}