#include <iostream>
#include <cmath>
#include <string.h>


// The solution is not *working*


// http://www.codechef.com/MARCH12/problems/LUCKY2

// All the lucky numbers below 1001
const int kAcceptedDigits[] = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
const long kMod = 1000000007;

const int kDigitCount = 12; // count of the above array

unsigned long long choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}

unsigned long long F(int i, int j)
{
	if(i < j) return 0;
	// 2 power j * iCj * 8 pow i-j
	return (choose(i, j) % kMod) * (1 << (3 * i - 2 * j) % kMod);
	//std::powl(2, 3 * i - 2 * j)
}

void LUCKY2()
{
	int T, Lc, Rc;
	unsigned long long count;
	scanf("%i", &T);

	char L[1002], R[1002];

	while(T-- > 0)
	{
		count = 0;
		scanf("%s %s", &L, &R);
		Lc = strlen(L);
		Rc = strlen(R);
		if(Rc < kAcceptedDigits[0])
		{
			printf("%llu\n", count);
			continue;
		}
		
		if(Lc != Rc)
		{
			for(int i = 0; i < kDigitCount; i++)
			{
				int s = kAcceptedDigits[i];
				unsigned long long temp = (F(Rc-1, s) - F(Lc, s)) + kMod;
				// std::cout << temp << std::endl;
				count = (count + temp) % kMod;
			}
		}

		// TODO: Handle i = Lc, i = Rc separately...
		unsigned long long count2 = 0;
		if(Lc >= 4)
		{
			int fixed = 0;
			for(int i = 0; i < Lc; i++)
			{
				int digit = L[i] - '0';
				int p = digit > 1 ? (digit - 1) : 0;
				int q = 0;
				if(digit > 7)
				{
					p -=2;
					q += 2;
				}
				else if(digit > 4)
				{
					p--; q++;
				}
				for(int j = 0; j < kDigitCount; j++)
				{
					unsigned long long temp1 = p * (F(Lc - i - 1, kAcceptedDigits[j] - fixed) % kMod);
					unsigned long long temp2 = q * (F(Lc - i - 1, kAcceptedDigits[j] - fixed - 1) % kMod);
					count2 = (count2 + temp1 + temp2) % kMod;
				}

				if(digit == 4 || digit == 7)
					fixed++;
			}
		}

		//std::cout << "count2" << count2 << std::endl;

		unsigned long long count3 = 0;
		if(Rc >= 4)
		{
			int fixed = 0;
			for(int i = 0; i < Rc; i++)
			{
				int digit = R[i] - '0';

				// Last digit of the number & it is equal to 4 or 7
				// Hack to consider including R also!!
				if(i == Rc - 1 && (digit == 4 || digit == 7)) {
					digit++;
				}
				int p = digit > 1 ? (digit - 1) : 0;
				int q = 0;
				if(digit > 7)
				{
					p -=2;
					q += 2;
				}
				else if(digit > 4)
				{
					p--; q++;
				}
				for(int j = 0; j < kDigitCount; j++)
				{
					unsigned long long temp1 = p * (F(Rc - i - 1, kAcceptedDigits[j] - fixed) % kMod);
					unsigned long long temp2 = q * (F(Rc - i - 1, kAcceptedDigits[j] - fixed - 1) % kMod);
					count3 = (count3 + temp1 + temp2) % kMod;
				}

				if(digit == 4 || digit == 7)
					fixed++;
			}
		}

		//std::cout << "count3" << count3 << std::endl;

		printf("%llu\n", (count - count2 + count3) % kMod);
	}
}