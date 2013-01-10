#include <iostream>
#include <cmath>
#include <string.h>

using std::cin;
using std::cout;

// http://www.codechef.com/MARCH12/problems/SHUTTLE

int gcd(int a, int b)
{
    for (;;)
    {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b)
{
    int temp = gcd(a, b);
    return temp ? (a / temp * b) : 0;
}

void SHUTTLE()
{
	int T(0), N(0);
	scanf("%i", &T);
	while(T-- > 0)
	{
		int count = 1;
		scanf("%i", &N);

		// Check per service
		for(int i = 2; i < N; i++)
		{
			int lcm_factor = lcm(N, i) / N;
			if(lcm_factor >= i)
				count++;
		}

		printf("%i\n", count);
	}
}
