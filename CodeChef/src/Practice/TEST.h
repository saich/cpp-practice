#include <iostream>

// http://www.codechef.com/problems/TEST/
void EchoInput()
{
	int n;
	while(true)
	{
		std::cin >> n;
		if(n == 42)
			break;
		std::cout << n << std::endl;
	}

}