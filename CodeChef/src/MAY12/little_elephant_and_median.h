#include <iostream>
#include <map>

typedef std::map<int,int> Map;

// PROBLEM: http://www.codechef.com/problems/MEDIAN/
// EDITORIAL: http://www.codechef.com/wiki/may-2012-contest-problem-editorials
// DYNAMIC PROGRAMMING...

Map cache;

int CountOperations(int mask, const int n)
{
	// count the 1 in the bit mask...
	int c1 = 0, c0 = 0;
	for(int i = 0; i < n; i++)
	{
		if(mask & (1 << i))
			c1++;
		else
			c0++;
	}

	if(c1 == n)
		return 0;

	if(c1 >= c0)
		return 1;

	// If already calculated, use it..
	if(cache.find(mask) != cache.end())
	{
		return cache[mask];
	}

	int count = 30; // This should be INFINITY, but since n <= 30, this works fine!!

	for(int i = 0; i < n; i++)
	{
		c1 = 0; c0 = 0;
		int target = mask;
		int temp_target = mask;
		bool bConsider = false;

		// For this i, choose the longest possible j...

		for(int j = i; j < n; j++)
		{
			// considering the sub-array [i,j]
			// calculate the bits set in [i,j]
			if(mask & (1 << j))
				c1++;
			else 
			{
				temp_target += (1 << j);
				c0++;
			}

			if(c1 >= c0 && temp_target != mask) 
			{
				// This subset can be considered to proceed, since this contain enough 1s in it.
				bConsider = true;
				target = temp_target;
			}
		}

		if(bConsider)
		{
			// From this i value? Or previous i value?
			count = std::min(count, 1 + CountOperations(target, n));
		}
	}

	// cache the data...
	cache[mask] = count;

	return count;
}

int little_elephant_and_median()
{
	int T, n;
	scanf("%d", &T);
	int A[30];
	while(T-- > 0)
	{
		cache.clear(); // Reset the cache map

		scanf("%d", &n);
		int max = 0;
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &A[i]);
			if(A[i] > max)
				max = A[i];
		}

		// convert the input array to bit mask, based on max..
		// since, we are not bothered by the value each element, but only if it is max. or not..
		int mask = 0;
		for(int i = 0; i < n; i++)
		{
			if(A[i] == max)
				mask += (1 << i);
		}

		printf("%d\n", CountOperations(mask, n));
	}
	return 0;
}