#include <iostream>

int cupcakes()
{
	int T, N, diff;
	scanf("%d", &T);
	while(T-- > 0) {
		scanf("%d", &N);
		diff = N - 1;
		for(int i = 2; i * i <= N; i++)
		{
			if(N % i == 0) {
				diff = (N/i) - (i);
			}
		}
		printf("%d\n", diff);
	}
	return 0;
}