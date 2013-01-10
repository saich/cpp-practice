#include <iostream>
#include <string.h>

int lucky_lucky_number()
{
	int T;
	scanf("%d", &T);
	int N;
	while(T-- > 0)
	{
		scanf("%d", &N);
		int b = 0;
		for(b = 0; b <= N; b+=4)
		{
			if((N - b) % 7 == 0)
			{
				break;
			}
		}
		printf("%d\n", b <= N ? (N - b) : -1);
	}
	return 0;
}