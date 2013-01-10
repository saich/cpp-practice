#include <iostream>
#include <string>
#include <string.h>

int string_reduction()
{
	int T, n, num_a, num_b, num_c, i;
	scanf("%d", &T);
	char s[100001];
	while(T-- > 0)
	{
		scanf("%s", s);
		n = strlen(s);
		num_a = num_b = num_c = 0;
		for(i = 0; i < n; ++i)
		{
			if(s[i] == 'a')
				num_a++;
			else if(s[i] == 'b')
				num_b++;
			else
				num_c++;
		}

		if(num_a == n || num_b == n || num_c == n)
		{
			// All the characters are same...
			printf("%d\n", n);
		}
		else if(num_a % 2 == num_b % 2 && num_b % 2 == num_c % 2)
		{
			// All num_a, num_b, num_c are even or odd..
			printf("%d\n", 2);
		}
		else
		{
			printf("%d\n", 1);
		}
	} // test case..
	return 0;
}