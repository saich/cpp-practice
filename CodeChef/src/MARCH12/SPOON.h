#include <iostream>
#include <cmath>
#include <string.h>

using std::cin;
using std::cout;

// http://www.codechef.com/MARCH12/problems/SPOON

inline void SPOON()
{
	typedef short i_type;
	i_type T;
	cin >> T;


	char M[100 * 100];
	i_type Cache[100 * 100];

	size_t cs;

	while(T-- > 0)
	{
		i_type R, C;
		cin >> R >> C;
		memset( M, 0, 100 * 100 * sizeof(char) );
		memset( Cache, 0, 100 * 100 * sizeof(char) );
		cs = 0;

		getchar(); // discard \n
		for(i_type i = 0; i < R; i++)
		{
			for(i_type j = 0; j < C; j++)
			{
				char ch = getchar();
				i_type idx = i * C + j;
				// TODO: if char is 's' or 'S', cache the position
				if((i <= R - 5 || j <= C - 5) && (ch == 's' || ch == 'S'))
					Cache[cs++] = idx;
				M[idx] = ch;
			}
			getchar(); // for \n
		}

		bool bSpoon(false);

		for(i_type i = 0; i < cs; i++)
		{
			size_t pos = Cache[i];

			if(
				((M[pos + 1] == 'p' || M[pos + 1] == 'P') &&
				(M[pos + 2] == 'o' || M[pos + 2] == 'O') &&
				(M[pos + 3] == 'o' || M[pos + 3] == 'O') &&
				(M[pos + 4] == 'n' || M[pos + 4] == 'N')) || 

				((M[pos + C] == 'p' || M[pos + C] == 'P') &&
				(M[pos + 2*C] == 'o' || M[pos + 2*C] == 'O') &&
				(M[pos + 3*C] == 'o' || M[pos + 3*C] == 'O') &&
				(M[pos + 4*C] == 'n' || M[pos + 4*C] == 'N'))
			)
			{
				// There is spoon
				bSpoon = true;
				break;
			}
		}

		if(bSpoon)
			cout << "There is a spoon!\n";
		else
			cout << "There is indeed no spoon!\n";
	}
}
