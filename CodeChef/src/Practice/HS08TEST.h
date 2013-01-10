#include <iostream>
#include <iomanip>

// Problem:	http://www.codechef.com/status/HS08TEST,saiprasad
void CheckATMBalance()
{
	unsigned int X;
	double Y;
	std::cin >> X >> Y;
	if(X % 5 == 0 && Y >= X + 0.50)
	{
		Y -= (X + 0.50);
	}
	std::cout.setf(std::ios::fixed);
	std::cout << std::setprecision(2) << Y;
}