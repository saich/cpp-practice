#include <iostream>
#include <algorithm>

// Problem:	http://www.codechef.com/problems/DPC206/

inline bool IsPalindrome(short digits[], size_t size)
{
	for(size_t i = 0; i < size / 2; i++)
	{
		if(digits[i] != digits[size - 1 - i])
			return false;
	}
	return true;
}

void Palindrome()
{
	short N, *digits(NULL), *newNumber(NULL), digitsCount, counter;
	unsigned long P; // P <= 2^32
	std::cin >> N;
	digits = new short[32];
	newNumber = new short[32];
	while(N-- > 0)
	{
		std::cin >> P;
		digitsCount = 0;
		counter = 0;
		// Convert P into an array of int, in reverse order
		while(P != 0)
		{
			digits[digitsCount++] = P % 10;
			P /= 10;
		}

		while(true)
		{
			counter++;
			int carry = 0;
			// Add P to P-reverse
			for(int i = 0; i < digitsCount; i++)
			{
				int temp = digits[i] + digits[digitsCount - 1 - i];
				newNumber[i] = (carry + temp) % 10;
				carry = temp / 10;
			}
			
			if(carry > 0)
			{
				newNumber[digitsCount++] = carry;
			}

			// Check if result is Palindrome
			if(IsPalindrome(newNumber, digitsCount))
			{
				std::cout << counter << " ";
				for(size_t i = 0; i < digitsCount; i++)
					std::cout << newNumber[i];
				std::cout << std::endl;
				break;
			}
			else
			{
				std::swap(newNumber, digits);
			}
		}
	}
	delete[] digits;
	digits = NULL;
	delete[] newNumber;
	newNumber = NULL;
}