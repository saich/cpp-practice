#include <iostream>

// Problem:	http://www.codechef.com/problems/MARCHA2
void BinaryTreeBean()
{
	short t;
	scanf("%hi", &t);

	long k;
	while(t-- > 0)
	{
		scanf("%li", &k);
		long long stemCount = 1;
		long long leaves;
		bool isValid = true;
		for(long i = 0; i < k; i++)
		{
			scanf("%lli", &leaves);
			// This condition is eqally important!
			if(leaves < 0 || leaves > stemCount)
				isValid = false;
			stemCount =  (stemCount - leaves) << 1;
		}
		if(isValid && stemCount == 0)
			std::cout << "Yes\n";
		else
			std::cout << "No\n";
	}
}