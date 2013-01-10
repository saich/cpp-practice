#include <iostream>


// Failed Submission (Timed Out)
// Problem: https://csindia.interviewstreet.com/challenges/dashboard/#problem/4f5bab8c2d747

void Matrix()
{
	int T, N;

	scanf("%i", &T);
	
	while(T-- > 0)
	{
		scanf("%i", &N);
		const long total = N * N;

		short* A = new short[total];
		short* B = new short[total];
		short* C = new short[total];

		for(int i = 0; i < total; i++)
		{
			scanf("%hi", &A[i]);
		}

		for(int i = 0; i < total; i++)
		{
			scanf("%hi", &B[i]);
		}

		for(int i = 0; i < total; i++)
		{
			scanf("%hi", &C[i]);
		}

		bool bRet = true;

		for(size_t i = 0; i < N; i++)
		{
			for(size_t j = 0; j < N && bRet; j++)
			{
				const short expected_val = C[(i * N) + j];

				short temp(0);
				for(size_t k = 0; k < N; k++)
				{
					temp = (temp + A[(i * N) + k] * B[(k * N) + j]);
					if(temp != 0 && expected_val == 0)
					{
						bRet = false;
						break;
					}
				}

				if(expected_val == 1 && temp == 0)
				{
					bRet = false;
					break;
				}
			}
		}

		if(bRet)
			printf("yes\n");
		else
			printf("no\n");

		delete[] A;
		delete[] B;
		delete[] C;
	}
}