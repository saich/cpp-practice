#include <iostream>
#include <string.h>

// https://www.interviewstreet.com/challenges/dashboard/#problem/4edb8abd7cacd
// String Similarity

// Uses the Z Algorithm
// @see http://cs.uef.fi/~kilpelai/BSA07/lectures/slides02.pdf
// @see http://comeoncodeon.wordpress.com/2010/08/29/the-z-algorithm/

int string_similarity()
{
	int T;
	scanf("%d", &T);

	const int kMax = 100000;

	char str[kMax + 1];
	int Z[kMax + 1];

	int N; // length of the input string

	int sum;
	while(T-- > 0)
	{
		int sum = 0;
		memset(Z, 0, (kMax + 1) * sizeof(int));
		
		scanf("%s", &str);
		N = strlen(str);

		Z[0] = N; sum = N;
		int r = 0, l = 0;
		for(int i = 1; i < N; i++)
		{
			if(i > r)
			{
				// no shortcut..
				int j;
				for(j = i; j < N && str[j] == str[j - i]; j++);
				if(j > i)
				{
					Z[i] = j - i;
					l = i;
					r = j - 1;
				}
			}
			else
			{
				int kt = i - l, b = r - i + 1;
				if(Z[kt] >= b)
				{
					// Work hard...
					// TODO: CODE DUPLICATE...
					int j;
					for(j = r + 1; j < N && str[j] == str[j - i];j++);
					Z[i] = j - i;
					l = i;
					r = j - 1;
				}
				else
				{
					Z[i] = Z[kt];
				}
			}

			sum += Z[i];

		} // for...

		printf("%d\n", sum);
	} // End of test case..

	return 0;
}