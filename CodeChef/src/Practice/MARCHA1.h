#include <iostream>

// Problem:		http://www.codechef.com/problems/MARCHA1/
// Tutorial:	http://www.codechef.com/wiki/tutorial-paying
void GangsterPayup()
{
	unsigned short t;
	scanf("%hu", &t);

	unsigned short n, notes[20];
	unsigned int m, sum;
	for(unsigned short i = 0; i < t; i++)
	{
		// Take input
		scanf("%hu", &n);
		scanf("%lu", &m);
		for(unsigned short i = 0; i < n; i++)
		{
			scanf("%hu", &notes[i]);
		}

		// Evaluate by brute force
		for(unsigned long i = 1, perms = 1L << n; i < perms; i++)
		{
			sum = 0;
			// Calculate the sum for this permutation
			for(unsigned short j = 0; j < n; j++)
			{
				if((i & (1 << j)) > 0) // jth- bit is set in i
					sum += notes[j];
			}
			if(sum == m)
			{
				printf("%s\n", "Yes");
				break;
			}
			if(i == perms - 1)
			{
				printf("%s\n", "No");
				break;
			}
		}
	}
}