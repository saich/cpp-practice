#include <iostream>
#include <vector>
#include <algorithm>

// TIME LIMIT EXCEEDED!!

typedef unsigned long long ull;

int divisible_pairs()
{
	int T, N, M;
	scanf("%d", &T);
	while(T-- > 0)
	{
		scanf("%d%d", &N, &M);
		ull count = 0;

		for(int S = M; S <= 2 * N; S += M)
		{
			int half = (S-1)/2;

			int b_max = N < (S - 1) ? N : (S - 1);
			int b_poss =b_max - half;
			// a -> [1, (S-1)/2]
			// b -> [(S+1)/2, min(N, S - 1)]
			int a_poss = half - ((S - 1) - b_max);
			count = count + ((a_poss < b_poss) ? a_poss : b_poss);
		}

		std::cout << count << std::endl;
	}
	return 0;
}