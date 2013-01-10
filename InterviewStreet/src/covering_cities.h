#include <iostream>
#include <vector>
#include <algorithm>

int covering_cities()
{
	int N, K;
	scanf("%d%d", &N, &K);
	std::vector<int> cities(N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d", &cities[i]);
	}

	std::sort(cities.begin(), cities.end());

	size_t curr_index = 0;
	size_t count = 1; // number of towers...
	int last_tower = cities[0] + K;

	for(size_t i = 1; i < cities.size(); ++i)
	{
		if(cities[i] > last_tower + K) {
			last_tower = cities[i] + K;
			count++;
		}
	}

	printf("%d", count);

	return 0;
}