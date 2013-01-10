#include <iostream>

// Problem: http://www.codechef.com/problems/NUMGAME/

void NumberGame()
{
	int T;
	long N;
	std::cin >> T;
	while(T-- > 0)
	{
		std::cin >> N;
		if(N % 2 == 0)
			std::cout << "ALICE";
		else
			std::cout << "BOB";
		std::cout << std::endl;
	}
}