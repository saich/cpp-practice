#include <iostream>

// Problem:	http://www.codechef.com/problems/DCE05/
void TitanicInterview()
{
	unsigned long t; // 10^6 is the max. i/p
	scanf("%lu", &t);
	unsigned long long int n, ans; // 10^12 is the limit 
	for(unsigned long i = 0; i < t; i++)
	{
		scanf("%llu", &n);
		ans = 1;
		while(n != 1)
		{
			n /= 2; // Divide by 2
			ans *= 2; // multiply by 2
		}
		printf("%llu\n", ans);
	}
}