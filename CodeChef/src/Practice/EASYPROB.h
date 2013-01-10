#include <iostream>

#define ISBITSET(number, position) ( (number >> position) % 2 == 1 )

// Return the number of bits in the number
inline size_t NumberOfBits(size_t number)
{
	size_t count = 0;
	for(count = 0; number != 0; count++, number = number >> 1);
	return count;
}

// Print the required form of a number
void ProcessNumber(int number)
{
	if(number == 0)
	{
		std::cout << "0";
		return;
	}

	size_t bitsCount = NumberOfBits(number);
	bool isFirstTerm = true;
	for(int i = bitsCount - 1; i >= 0; i--)
	{
		if( ISBITSET(number, i) )
		{
			if(!isFirstTerm)
				std::cout << "+";
			std::cout << "2";
			if(i != 1)
			{
				std::cout << "(";
				ProcessNumber(i);
				std::cout << ")";
			}
			isFirstTerm = false;
		}
	}
}

void StrangeBinaryFormatOfNumbers()
{
	// EASYPROB - http://www.codechef.com/problems/EASYPROB/
	const int input[] = {137, 1315, 73, 136, 255, 1384, 16385};
	for(int i = 0, j = sizeof(input) / sizeof(int); i < j; i++)
	{
		std::cout << input[i] << "=";
		ProcessNumber( input[i] );
		std::cout << std::endl;
	}
}