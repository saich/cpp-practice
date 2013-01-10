#include <iostream>

// Problem:	http://www.codechef.com/problems/TLG/
void BilliardWinner()
{
	unsigned int N;
	scanf("%u", &N);
	unsigned short s,t;
	int totalLead(0), maxLead(0), tempLead;
	unsigned short W;
	for(unsigned int i = 0; i < N; i++)
	{
		scanf("%hu%hu", &s, &t);
		totalLead += s-t;
		tempLead = (totalLead > 0) ? totalLead : -1 * totalLead;

		if(tempLead > maxLead)
		{
			maxLead = tempLead;
			W = (totalLead > 0) ? 1: 2;
		}
	}
	printf("%hu %i\n", W, maxLead);

}