#include <iostream>
typedef unsigned long long ull;

int candies()
{
	int T, N, C, temp;
	scanf("%d", &T);
	while(T-- > 0) {
		scanf("%d%d", &N, &C);
		ull sum = 0;
		for(int i = 0; i < N; i++) {
			scanf("%d", &temp);
			sum += (ull)temp;
		}

		printf("%s\n", (C < sum) ? "No" : "Yes");
	}

	return 0;
}