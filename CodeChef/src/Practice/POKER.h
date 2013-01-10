#include <iostream>
#include <algorithm>

// Problem:	http://www.codechef.com/problems/POKER/

const short kCardCount = 5;

class Card
{
public:
	char kind;
	char suite;
	
	inline short GetValue() const
	{
		return value;
	}

	void CalculateValue()
	{
		if(kind > '1' && kind <= '9')
			value = kind - '0';
		else if(kind == 'T')
			value = 10;
		else if(kind == 'J')
			value = 11;
		else if(kind == 'Q')
			value = 12;
		else if(kind == 'K')
			value = 13;
		else if(kind == 'A')
			value = 14;
		else
			value = 0;
	}
private:
	short value;
};

bool operator<(const Card& c1, const Card& c2)
{
	return c1.GetValue() < c2.GetValue();
}

void ThePokerHands()
{
	short t;
	std::cin >> t;
	Card ip[kCardCount];

	while(t-- > 0)
	{
		// Take input
		for(size_t i = 0; i < kCardCount; i++)
		{
			std::cin >> ip[i].kind >> ip[i].suite;
			ip[i].CalculateValue();
		}

		std::sort(ip, ip + kCardCount);

		// Check if all belong to same suite --> royal flush, straight flush, flush
		bool bSameSuite(true), bSequential(true);
		short differentKinds = (kCardCount > 0) ? 1 : 0;
		short maxCount(0), currentCount(1);
		for(size_t i = 0; i < kCardCount - 1; i++)
		{
			if(bSameSuite && ip[i].suite != ip[i + 1].suite)
			{
				bSameSuite = false;
			}

			// Check if sequential
			if(bSequential && ip[i].GetValue() + 1 != ip[i+1].GetValue()
				&& !(i + 2 == kCardCount && ip[i+1].GetValue() == 14 && ip[0].GetValue() == 2))
			{
				bSequential = false;
			}

			if( ip[i].GetValue() != ip[i + 1].GetValue() )
			{
				differentKinds++;
				currentCount = 1;
			}
			else
			{
				currentCount++;
				if(currentCount > maxCount)
					maxCount = currentCount;
			}
		}

		if(bSameSuite && bSequential)
		{
			 if(ip[0].GetValue() == 10)
				 std::cout << "royal flush";
			 else
				 std::cout << "straight flush";
		}
		else if(differentKinds == 2)
		{
			if(maxCount == 4)
				std::cout << "four of a kind";
			else// if(maxCount == 3)
				std::cout << "full house";
		}
		else if(bSameSuite)
		{
			std::cout << "flush";
		}
		else if(bSequential)
		{
			std::cout << "straight";
		}
		else if(differentKinds == 3)
		{
			if(maxCount == 3)
				std::cout << "three of a kind";
			else if(maxCount == 2)
				std::cout << "two pairs";
		}
		else if(differentKinds == 4)
			std::cout << "pair";
		else
			std::cout << "high card";

		std::cout << std::endl;
	}
}