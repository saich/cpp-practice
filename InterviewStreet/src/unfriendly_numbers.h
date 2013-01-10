#include <iostream>
#include <vector>
#include <cmath>

typedef unsigned int ui;
typedef unsigned long ul;
typedef long long ll;
typedef unsigned long long ull;

// scanfs
#define SUL(x) scanf("%lu", &x)
#define SLL(x) scanf("%ll", &x)
#define SULL(x) scanf("%llu", &x)


#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) FOR(i,0,n-1)
#define FOREACH(i,x) for(__typeof((x).begin()) i=(x.begin()); i!=(x).end(); ++i)
#define ALL(x) x.begin(),x.end()
#define PB push_back


typedef std::vector<ul> vul;
typedef std::vector<ull> vull;


void unfriendly_nums()
{
	
	// Try Brute Force...

	ull N; ul K;

	bool zero(false);

	// Take input..
	SULL(N); SUL(K);

	vull unfriendlies(N);
	REP(i, N)
	{
		SULL(unfriendlies[i]);
		if(!zero && unfriendlies[i] % K == 0)
			zero = true;
	}

	if(zero) {
		printf("%d", 0); return;
	}

	// Find all factors of K..
	ul sqt = std::sqrtl(K);

	vul factors;
	for(ul i = 2; i <= sqt; i++)
	{
		if(K % i == 0)
		{
			// Add to factors array..
			factors.PB(i); 
			if(i != sqt)
				factors.PB(K / i);
		}
	}

	factors.PB(K);

	ul count(0);
	for(ul i = 0; i < factors.size(); i++)
	{
		bool bSuccess(true);
		for(ull j = 0; j < N; j++)
		{
			if(unfriendlies[j] % factors[i] == 0)
			{
				bSuccess = false;
				break;
			}
		}

		if(bSuccess)
			count++;
	}

	printf("%lu", count);
}