#include <iostream>

// Problem:	http://www.codechef.com/problems/PERMUT2/
void CheckAmbigiousPermutation()
{
	unsigned long n, i;
	scanf("%lu", &n); // 10^6
	while(n != 0)
	{
		unsigned long *a = new unsigned long[n];
		unsigned long *b = new unsigned long[n];
		for(i = 0; i < n; i++)
		{
			// Take input
			scanf("%lu", &a[i]);
			// Calculate the reverse permutation
			b[a[i] - 1] = i + 1;
		}

		for(i = 0; i < n; i++)
		{
			if(a[i] != b[i])
				break;
		}
		if(i == n)
			printf("%s\n", "ambiguous");
		else
			printf("%s\n", "not ambiguous");

		delete[] a;
		delete[] b;

		scanf("%lu", &n); // Take next input
	}
}