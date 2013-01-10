#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Problem:	http://www.codechef.com/problems/TSORT/
void TurboSort()
{
	// TODO - Looks like Bucket Sort can also be effective here,
	// if duplicates are properly dealt.
	unsigned int t; // short won't be suff.
	scanf("%u", &t);
	std::vector<unsigned int> data(t);
	
	// Take i/p
	for(unsigned int i = 0; i < t; i++)
	{
		scanf("%u", &data[i]); 
	}

	std::sort(data.begin(), data.end());

	std::copy(data.begin(), data.end(), 
		std::ostream_iterator<unsigned int>(std::cout, "\n"));
}