#include <iostream>
#include <vector>
#include <algorithm>

// Based on http://stackoverflow.com/questions/10402087/algorithm-for-minimum-manhattan-distance

typedef std::vector<int> ivec;
typedef unsigned long long ull;

int home_for_chef()
{
	int T, N;
	scanf("%d", &T);
	ivec x,y;
	while(T-- > 0)
	{
		scanf("%d", &N);
		x.resize(N);
		y.resize(N);

		for(int i = 0; i < N; i++)
		{
			scanf("%d%d", &x[i], &y[i]);
		}

		if(N % 2 == 1)
		{
			printf("%d\n", 1);
			continue;
		}

		int mid1 = N / 2;
		int mid2 = mid1 - 1;
		std::nth_element(x.begin(), x.begin() + mid1, x.end());
		std::nth_element(y.begin(), y.begin() + mid1, y.end());

		std::nth_element(x.begin(), x.begin() + mid2, x.end());
		std::nth_element(y.begin(), y.begin() + mid2, y.end());

		int x_min = x[mid2], y_min = y[mid2], x_max = x[mid1], y_max = y[mid1];
		
		ull count = static_cast<ull>(x_max - x_min + 1) * static_cast<ull>(y_max - y_min + 1);
		std::cout << count << std::endl;
	}
	return 0;
}
