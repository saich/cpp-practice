#include <iostream>

typedef unsigned long ul;

// https://adobe.interviewstreet.com/challenges/dashboard/#problem/4f651708b2919

// WRONG ANSWER!! MISSED THE CONSECUTIVE PART IN THE QUESTION

const int kMaxN = 1000;

#define MOD 1000000007

unsigned long long Facts[kMaxN + 1];

int group_game()
{
	int T, N, K;
	scanf("%d", &T);

	int all[kMaxN]; // skills of all employees
	int group[kMaxN]; // skills of the sales group

	// Precalculate all the factorials
	Facts[0] = 1;
	for(int i = 1; i <= kMaxN; i++)
	{
		Facts[i] = (Facts[i - 1] * i) % MOD;
	}
	
	while(T-- > 0)
	{
		// Take input
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
		{
			scanf("%d", &all[i]);
		}

		scanf("%d", &K);
		for(int i = 0; i < K; ++i)
		{
			scanf("%d", &group[i]);
		}

		// Min. & max. of the group..
		int groupMin(group[0]), groupMax(group[0]);
		for(int i = 1; i < K; ++i)
		{
			int curr = group[i];
			if(curr > groupMax)
				groupMax = curr;

			if(curr < groupMin)
				groupMin = curr;
		}

		// No. of total employees with skill >= groupMax, skill < groupMin
		int nLess(0), nGreat(0);
		for(int i = 0; i < N; ++i)
		{
			if(all[i] >= groupMax)
				++nGreat;
			else if(all[i] < groupMin)
				++nLess;
		}

		unsigned long long total = 0;

		int kewl[kMaxN];
		kewl[0] = 1;
		for(int i = 1; i <= nLess; i++)
		{
			kewl[i] = (kewl[i - 1] * (nLess - i + 1)) % MOD;
		}

		for(int i = 0; i <= nLess; i++)
		{	
			total = total + (kewl[i] * Facts[N - i - 1]) % MOD;
		}

		total = (total * nGreat) % MOD;
		printf("%llu\n", total);
	}

	return 0;
}