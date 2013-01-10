#include <iostream>
#include <string>
#include <algorithm>

// Problem: http://www.codechef.com/problems/CMB01/

inline int getValue(const std::string& str, size_t index)
{
	return ( index < str.size() ) ? str[index] - '0' : 0;
}

void ArabicNumbers()
{
	int N;
	std::cin >> N;
	std::string a, b;
	while(N-- > 0)
	{
		std::cin >> a >> b;
		// TODO - Maybe I require to remove the trailing & ending zeroes from the input
		size_t maxSize = std::max( a.size(), b.size() );
		int carry = 0, val;
		bool ignoreZeroes = true;
		for(size_t i = 0; i < maxSize; i++)
		{
			val = carry + getValue(a, i) + getValue(b, i);
			carry = val / 10;
			val = val % 10;
			if(val || !ignoreZeroes)
			{
				ignoreZeroes = false;
				std::cout << val;
			}
		}

		if(carry) std::cout << carry;

		std::cout << std::endl;
	}
}