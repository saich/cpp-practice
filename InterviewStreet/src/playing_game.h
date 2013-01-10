#include <iostream>

// https://csindia.interviewstreet.com/challenges/dashboard/#problem/4f5c3e92860d1

int Playing_Game()
{
	int N1, N2, T;
	std::cin >> T;
	while(T-- > 0)
	{
		std::cin >> N1 >> N2;

		if(N1 % 2 == 0 || N2 % 2 == 0)
			std::cout << "Alice\n";
		else
			std::cout << "Bob\n";
	}
	return 0;
}