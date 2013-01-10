#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

void SmallFactorials()
{
	// Problem:		http://www.codechef.com/problems/FCTRL2/
	// Tutorial:	http://www.codechef.com/wiki/tutorial-small-factorials
	int t, n;
	std::cin >> t; // 1<=t<=100
	for(int i = 0; i < t; i++)
	{
		std::cin >> n; // 1<=n<=100

		std::vector<int> fact;
		fact.push_back(1);

		for(int i = 2; i <= n; i++)
		{
			int carry = 0;
			// Multiply the current fact with i
			for(size_t j = 0; j < fact.size(); j++)
			{
				int temp = carry + fact[j] * i;
				fact[j] = temp % 10;
				carry = temp / 10;
			}

			// Add the carry back to the result
			while(carry != 0)
			{
				fact.push_back(carry % 10);
				carry /= 10;
			}
		}

		// Output the factorial
		std::copy( fact.rbegin(), fact.rend(), std::ostream_iterator<int> (std::cout, "") );
		std::cout << std::endl;
	}
}