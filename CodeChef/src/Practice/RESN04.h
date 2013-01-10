#include <iostream>
#include <vector>

// Problem:	http://www.codechef.com/problems/RESN04/

void StoneProblem()
{
	short t, N;
	std::cin >> t;
	
	for(short i = 0; i < t; i++)
	{
		std::cin >> N;
		std::vector<short> s(N + 1);
		for(int i = 1; i <= N; i++)
		{
			std::cin >> s[i];
		}

		short index(1);
		bool bAlice(false);
		while(index <= N)
		{
			if(s[index] >= index)
			{
				s[index] -= index;
				bAlice = !bAlice;
			}
			else
			{
				index++;
			}
		}
		if(bAlice)
			std::cout << "ALICE\n";
		else
			std::cout << "BOB\n";
	}
}