#include <iostream>

void EnormousInputOutput()
{
	// http://www.codechef.com/problems/INTEST/
	int n, k, num;
	std::cin >> n >> k;
	int count = 0;
	for(int i = 0; i < n; i++)
	{
		// cin causes timeout here!
		// Practical example to show cin && cout is much slower than scanf & printf
		scanf("%d", &num);
		if(num % k == 0) count++;
	}
	std::cout << count << std::endl;
}
