#include <iostream>
#include <map>

// Problem:	http://www.codechef.com/problems/COINS/

std::map<unsigned long, unsigned long long> cache;

unsigned long long MaxCoins(unsigned long n)
{
	if(n == 0)
		return 0;
	if(cache.find(n) != cache.end())
		return cache[n];
	unsigned long long a = MaxCoins(n / 2) + MaxCoins(n / 3) + MaxCoins(n / 4);

	cache[n] = (a > n) ? a : n;
	return cache[n];
}
inline void CoinsToDollars()
{
	unsigned long n;
	while(std::cin >> n)
	{
		std::cout << MaxCoins(n) << std::endl;
	}
}