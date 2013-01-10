#include <iostream>

// Problem: http://www.codechef.com/problems/CMB02/

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
void NumericPalindrome()
{
	int t, k, numDigits, digits[6];
	scanf("%i", &t);
	while(t-- > 0)
	{
		numDigits = 0;
		scanf("%i", &k);
		k++;

		// Convert k into array of single digits
		while(k != 0)
		{
			digits[numDigits++] = k % 10;
			k /= 10;
		}

		// Convert
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


		// output k from numDigits - 1 to 0th index.
		while(--numDigits >= 0)
		{
			printf("%i", digits[numDigits]);
		}
		printf("%s", "\n");
	}
}