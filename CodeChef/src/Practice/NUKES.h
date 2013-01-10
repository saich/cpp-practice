#include <iostream>

// Problem: http://www.codechef.com/problems/NUKES/
void NukeCounter()
{
	unsigned long A;
	unsigned short N,K;
	std::cin >> A >> N >> K;

	for(unsigned short i = 0; i < K; i++)
	{
		std::cout << A % (N + 1) << " ";
		A /= (N + 1);
	}
}