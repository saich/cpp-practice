#include <iostream>
#include <string.h>

typedef unsigned long ul;

// https://adobe.interviewstreet.com/challenges/dashboard/#problem/4f64b38b41e5e

const ul kMax = 1000000 + 1;

double RES[kMax];

void GAME()
{
	double P;
	std::cin >> P;

	// Preprocess
	RES[0] = 0;
	RES[1] = P;
	for(ul i = 2; i < kMax; i++)
	{
		RES[i] = RES[i - 1] * ( 1 - (2 * P)) + (P);
	}

	ul Q, N;
	std::cin >> Q;
	while(Q-- > 0)
	{
		std::cin >> N;
		printf("%.4f\n", RES[N]);
		//std::cout << RES[N] << std::endl;
	}
}