#include <iostream>
#include <string.h>

// Problem: http://www.codechef.com/problems/GCD2/

template <class T>
T GCD(T a, T b)
{
	T c;
	while (a != 0) 
	{
		c = a;
		a = b % a;
		b = c;
	}
	return b;
}

void GCD2()
{
	long T; // No. of test cases
	std::cin >> T;

	long A;
	char B[251];
	long t;
	while(T-- > 0)
	{
		std::cin >> A >> B;

		if(A == 0)
		{
			// A = 0 special check is required - Else, arises Division By Zero condition
			std::cout << B << std::endl;
		}
		else
		{
			// Modulus can also be calculated in same way as division, on paper, going digit by digit
			t = 0;
			for(size_t i = 0, j = strlen(B); i < j; i++)
			{
				t = ( t * 10 + B[i] - '0') % A;
			}

			// Calculate the GCD b/w A, t since t = B % A [Euclid's Algorithm]
			std::cout << GCD(A, t) << std::endl;
		}
	}
}