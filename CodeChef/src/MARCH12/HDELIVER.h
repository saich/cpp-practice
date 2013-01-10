#include <iostream>
#include <cmath>
#include <string.h>

// http://www.codechef.com/MARCH12/problems/HDELIVER

void HDELIVER()
{
	int T(0), N(0), M(0), Q, temp1, temp2;
	scanf("%i", &T);

	short paths[100][100];

	while(T-- > 0)
	{
		int count = 1;
		scanf("%i %i", &N, &M);

		memset(paths, 0, sizeof(short) * 100 * 100);
		// Initialize paths[i][i] = 1
		for(int i = 0; i < N; i++)
		{
			paths[i][i] = 1;
		}
		
		for(int i = 0; i < M; i++)
		{
			scanf("%i %i", &temp1, &temp2);
			paths[temp1][temp2] = 1;
			paths[temp2][temp1] = 1;
		}


		//Slight variation of http://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm

		for(int k = 0; k < N; k++)
			for(int i = 0; i < N; i++)
				for(int j = 0; j < N; j++)
				{
					// path doesn't exist already!
					if(paths[i][j] != 1 && (paths[i][k] == 1 && paths[k][j] == 1))
					{
						paths[i][j] = 1;
						paths[j][i] = 1;
					}
				}

		scanf("%i", &Q);
		for(int i = 0; i < Q; i++)
		{
			scanf("%i %i", &temp1, &temp2);
			// TODO: Print output
			if(paths[temp1][temp2] == 1)
				printf("%s\n", "YO");
			else
				printf("%s\n", "NO");
		}


	}
}
