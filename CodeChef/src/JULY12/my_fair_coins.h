#include "template.h"

int main()
{
	clock_t start = clock();
	int T = input.readInt();
	while(T--) {
		int N = input.readInt();
		if(N == 1)
		{
			output(1, "\n");
			continue;
		}
		else if(N == 2)
		{
			output(3, "\n");
			continue;
		}
		N -= 2;
		int result[] = {1, 0, 0, 1};
		int mat[] = {2, 2, 1, 0}; // similar concept to the Fibonacci Matrix exponentiation...
		while(N > 0) {
			if(N & 1) 
			{
				// N is odd... result = result * mat
				int a = (static_cast<ull>(result[0]) * mat[0] + static_cast<ull>(result[1]) * mat[2]) % MOD;
				int b = (static_cast<ull>(result[0]) * mat[1] + static_cast<ull>(result[1]) * mat[3]) % MOD;
				int c = (static_cast<ull>(result[2]) * mat[0] + static_cast<ull>(result[3]) * mat[2]) % MOD;
				int d = (static_cast<ull>(result[2]) * mat[1] + static_cast<ull>(result[3]) * mat[3]) % MOD;

				result[0] = a;
				result[1] = b;
				result[2] = c;
				result[3] = d;
			}

			// mat = mat * mat
			int a = (static_cast<ull>(mat[0]) * mat[0] + static_cast<ull>(mat[1]) * mat[2]) % MOD;
			int b = (static_cast<ull>(mat[0]) * mat[1] + static_cast<ull>(mat[1]) * mat[3]) % MOD;
			int c = (static_cast<ull>(mat[2]) * mat[0] + static_cast<ull>(mat[3]) * mat[2]) % MOD;
			int d = (static_cast<ull>(mat[2]) * mat[1] + static_cast<ull>(mat[3]) * mat[3]) % MOD;

			mat[0] = a;
			mat[1] = b;
			mat[2] = c;
			mat[3] = d;

			N /= 2;
		}

	//	cout << result[0] << "," << result[1] << endl;
		int answer = (static_cast<ull>(result[0]) * 3 + static_cast<ull>(result[1]) * 1) % MOD;
		output(answer, "\n");
	}
	//cout << (double)(clock() - start) / CLOCKS_PER_SEC << "seconds" << endl;
	
	return 0;
}