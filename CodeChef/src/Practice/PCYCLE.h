#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

// Problem:	http://www.codechef.com/problems/PCYCLE/
class Number 
{
public:
	short number;
	bool bIsVisited;
	Number(short num = 0, bool visited = false)
		:number(num),
		bIsVisited(visited) {}
};

size_t FindFirstUnVisited(const std::vector<Number>& input)
{
	size_t i(1);
	for(; i < input.size(); i++)
	{
		if( !(input[i].bIsVisited) )
			break;
	}
	return i;
}

void PermutationCycles()
{
	short N;
	std::cin >> N;
	std::vector<Number> input(N + 1); // lets leave the 1st one empty!
	std::vector < std::vector<short> > output;

	for(short i = 1; i <= N; i++)
	{
		std::cin >> input[i].number;
	}

	// Find 1st unvisited
	size_t index = FindFirstUnVisited(input);
	while( index < input.size() )
	{
		std::vector<short> cycle;
		while (!input[index].bIsVisited)
		{
			cycle.push_back(index);
			input[index].bIsVisited = true;
			index = input[index].number;
		}
		cycle.push_back(index);
		output.push_back(cycle);
		index = FindFirstUnVisited(input);
	}

	// Output
	std::cout << output.size() << std::endl;

	for(size_t i = 0; i < output.size(); i++)
	{
		std::copy(output[i].begin(), output[i].end(), std::ostream_iterator<short>(std::cout, " "));
		std::cout << std::endl;
	}
}