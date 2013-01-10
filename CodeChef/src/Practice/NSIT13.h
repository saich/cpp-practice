#include <iostream>
#include <string.h>

// Problem: http://www.codechef.com/problems/NSIT13/

void Modulo()
{
	short t(10), ip, mod[42], count;
	while(t-- > 0)
	{
		count = 0;
		memset(mod, 0, 42 * sizeof(short));
		for(size_t i = 0; i < 10; i++)
		{
			scanf("%hi", &ip);
			if(!mod[ ip % 42 ]++) count++;
		}
		printf("%hi\n",count);
	}
}