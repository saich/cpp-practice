#include <iostream>
#include <cmath>

void dancing_with_googlers()
{
	int T, N, S, p, Ni;

	scanf("%d", &T);
	for(int tcase = 1; tcase <= T; tcase++)
	{
		scanf("%d%d%d", &N, &S, &p);
		int count (0);
		for(int i = 0; i < N; i++)
		{
			scanf("%d", &Ni);

			int mid = std::ceil(static_cast<double>(Ni) / 3);
			
			if(mid + 1 < p)
			{
				
			}
			else if(mid >= p) 
			{
				count++;
			}
			else if(3 * mid + 1 == Ni || 3 * mid + 2 == Ni)
			{
				// mid = p - 1 here...
				// No surprising triplet will be required here... (mid, mid, mid + 1) or (mid, mid + 1, mid + 1)
				count++;
			}
			else if(S > 0 && mid > 0 && (3 * mid >= Ni - 1) && (3 * mid <= Ni + 1))
			{
				// surprising triplet is required..
				count++; S--;
			}
		}

		printf("Case #%d: %d\n", tcase, count);
	}
}