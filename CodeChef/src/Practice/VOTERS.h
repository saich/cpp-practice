#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Problem: http://www.codechef.com/problems/VOTERS/
void VotersList()
{
	long N1, N2, N3;
	std::cin >> N1 >> N2 >> N3;
	long total = N1 + N2 + N3;
	std::vector<long> list(total);

	for(long i = 0; i < total; i++)
	{
		std::cin >> list[i];
	}

	// Sort the list
	std::inplace_merge(list.begin(), list.begin() + N1, list.begin() + N1 + N2);
	std::inplace_merge(list.begin(), list.begin() + N1 + N2, list.end());

	std::vector<long>::iterator it = std::adjacent_find(list.begin(), list.end());

	// Find the adjacent elements taking care that 3 same elements can also be present
	std::vector<long> output;
	while( it != list.end() )
	{
		output.push_back(*it);
		it = std::adjacent_find(it + 2, list.end());
	}

	// print the output
	std::cout << output.size() << std::endl;
	std::copy( output.begin(), output.end(), std::ostream_iterator<long>(std::cout,"\n") );
}
