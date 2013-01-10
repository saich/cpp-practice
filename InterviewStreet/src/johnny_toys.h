#include <iostream>
#include <string.h>
#include <map>

typedef unsigned long long ull;
void jonny_toys()
{
	const int kMax = 1000001;
	int N, weight;
	scanf("%d", &N);

	std::map<ull, int> w;

	for(int j = 0; j < N; j++)
	{
		scanf("%d", &weight);
		w[weight]++;
	}

	int i = 1 ;
	ull total_weight(0), first(0);

	std::map<ull, int>::iterator it = w.begin();
	while(it != w.end())
	{
		if(it->second > 0)
		{
			// got a number...
			if(first == 0)
			{
				first = it->first;
			}
			else
			{
				w[first + it->first]++;
				
				total_weight += (first + it->first);
				first = 0;
			}
			(it->second)--;
		}
		else
			++it; // jump to next position
	}

	std::cout << total_weight << std::endl;
}