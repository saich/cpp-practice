#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Problem: http://www.codechef.com/problems/NOTATRI/

typedef std::vector<unsigned long> LengthsVector;

void NotATriangle()
{
	unsigned int N;
	std::cin >> N;
	LengthsVector lengths;
	unsigned long maxSideLength;
	while(N != 0)
	{
		lengths.resize(N);
		for(size_t i = 0; i < N; i++)
			std::cin >> lengths[i];

		// Sort
		std::sort( lengths.begin(), lengths.end() );

		unsigned long counter(0);

		// Pick two sides & then determine the possible edges for 3rd side
		for(size_t i = 0; i < N - 2; i++)
		{
			for(size_t j = i + 1; j < N - 1; j++)
			{
				maxSideLength = lengths[i] + lengths[j]; // The other side must not be greater than maxSideLength
				// Search for the pivot element in [j + 1, N-1]
				LengthsVector::iterator upper = std::upper_bound(lengths.begin() + j + 1, lengths.end(), maxSideLength);
				counter += std::distance(upper, lengths.end());
			}
		}
		std::cout << counter << std::endl;
		std::cin >> N;
	}
}