#include <iostream>


// Problem:	http://www.codechef.com/problems/FCTRL/
// Logic:	http://en.wikipedia.org/wiki/Trailing_zero#Factorial
void CountTrailingZeroes()
{
	int T, N;
	std::cin >> T;
	for(int i = 0; i < T; i++)
	{
		std::cin >> N; // N must be atleast 32-bit
		// Now calculate the no. of trailing zeroes in N
		int count = 0, q = N;
		do
		{
			q = q / 5;
			count += q;
		} while (q != 0);
		std::cout << count << std::endl;
	}
}