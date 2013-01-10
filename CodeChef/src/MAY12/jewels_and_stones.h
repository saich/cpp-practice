#include <iostream>
#include <string.h>

void jewels_and_stones()
{
	int T;
	scanf("%d", &T);
	char J[101], S[101];
	while(T-- > 0)
	{
		bool jewels[255] = {0};
		int count = 0;
		scanf("%s%s", J, S);

		for(size_t i = 0, j = strlen(J); i < j;++i)
		{
			jewels[J[i]] = 1;
		}

		for(size_t i = 0, j = strlen(S); i < j;++i)
		{
			if(jewels[S[i]] == 1)
				count++;
		}
		printf("%d\n", count);
	}
}