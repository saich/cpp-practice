#include <iostream>
#include <cmath>

// Problem: http://www.codechef.com/problems/PRPALIN/

inline void Increment(int digits[], size_t size, size_t index)
{
	int carry = 1, temp;
	for(size_t i = index; i < size, carry > 0; i++)
	{
		temp = digits[i] + carry;
		digits[i] = temp % 10;
		carry = temp / 10;
	}
}

inline bool IsPrime(int N)
{
	int root = static_cast<int>(std::sqrt(static_cast<double>(N)));
	for(int i = 2; i <= root; i++) // <= example: 9
	{
		if(N % i == 0)
			return false;
	}
	return true;
}

void PrimePalindrome()
{
	int N, numDigits, digits[7];
	std::cin >> N;

	// Look into CMB02.h

	while(true)
	{
		numDigits = 0;

		// Convert N into array of digits
		while(N != 0)
		{
			digits[ numDigits++ ] = N % 10;
			N /= 10;
		}
	
		// Find the palindrome
		for(size_t i = 0, j = numDigits / 2, last = numDigits - 1; i < j; i++, last--)
		{
			if(digits[i] < digits[last])
			{
				digits[i] = digits[last];
			}
			else if(digits[i] > digits[last])
			{
				// Increment next digit
				Increment(digits, 6, i + 1);
				digits[i] = digits[last];
			}
		}
		// Convert digits back to number
		N = 0;
		while(numDigits-- > 0)
		{
			N = N * 10 + digits[numDigits];
		}
		// Check if N is Prime
		if(IsPrime(N))
		{
			std::cout << N;
			break;
		}
		N++; // Increment N
	}
}