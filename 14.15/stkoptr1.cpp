#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stcktp1.h"
const int Num = 10;
int main()
{
	std::srand(std::time(0));
	std::cout << "Plaese enter stack size: ";
	int stacksize;
	std::cin >> stacksize;
	Stack<const char *> st(stacksize);

	const char * in[Num] = {
		" 1: Hank Giladfqa", " 2: Kikl Isfasf",
		" 3: Betty afga", " 4: Ian Flasfgvs",
		" 5: Wolfgang Kiagw", " 6: Port Koop",
		" 7: Joy safaqv"," 8: Xaverir Pawgwqg",
		" 9: Juna Moaefr", " 10: Misha mache"
	};

	const char * out[Num];

	int processed = 0;
	int nextin = 0;
	while (processed < Num)
	{
		if (st.isempty())
			st.push(in[nextin++]);
		else if (st.isfill())
			st.pop(out[processed++]);
		else if(std::rand() % 2 && nextin < Num)
			st.push(in[nextin++]);
		else
			st.pop(out[processed++]);
	}
	for ( int i = 0; i < Num; i++)
		std::cout << out[i] << std::endl;

	std::cout << "Byte.\n";
	return 0;
}
		