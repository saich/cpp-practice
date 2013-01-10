#include <iostream>
#include <string>
#include <algorithm>

// Problem:	http://www.codechef.com/problems/TECH04/

inline void AnagramsTest()
{
	int T;
	std::cin >> T;
	while(T-- > 0)
	{
		std::string a, b;
		std::cin >> a >> b;
		std::sort(a.begin(), a.end());
		std::sort(b.begin(), b.end());
		std::cout << ((a == b) ? "YES\n" : "NO\n");
	}
}