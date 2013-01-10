#include <iostream>
#include <string.h>
#include <vector>

// K Difference
// https://www.interviewstreet.com/challenges/dashboard/#problem/4e14b83d5fd12

// @see http://stackoverflow.com/questions/7695723/optimizing-this-c-sharp-algorithm-k-difference

/*
Initial Possibilities:
	- Brute-Force: O(N-square), O(N) for each element
	- Sort the Input list: O(NlogN)
	- Partial Brute-Force, by using hash-table instead of array for input, O(N) + O(N) * O(1) i.e; O(N)
*/

/**
Current Implementation
 - Read an element x from input stream & insert it into a hash table H (really simple hash table of 9973 elements and modulo as hash function)
 - If(x - K) exists in H, count++
 - If(x + K) exists in H, count++
 */
int k_difference()
{
	const int kHashSize = 9973;

	const int kMax = 1e9;

	typedef std::vector<long> mylist;

	mylist H[kHashSize];
	int N, K, count(0), num, temp;
	scanf("%d%d", &N, &K);
	const int kDiff = kMax - K;
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &num);
		H[num % kHashSize].push_back(num);

		temp = num - K;
		mylist& l = H[temp % kHashSize];
		for(int i = 0, j = l.size(); i < j; ++i)
		{
			if(l[i] == temp)
			{
				count++;
				break;
			}
		}

		temp = num + K;
		mylist& l = H[temp % kHashSize];
		for(int i = 0, j = l.size(); i < j; ++i)
		{
			if(l[i] == temp)
			{
				count++;
				break;
			}
		}
	} // for loop

	printf("%d\n", count);

	return 0;
}