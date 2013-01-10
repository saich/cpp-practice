#include "template.h"
int val[100000];
int idx[100000];

bool mysort(int i, int j) { return val[i] != val[j] ? val[i] < val[j] : i < j; }
int main()
{
	int N = input.readInt(), K = input.readInt();
	for(int i = 0; i < N; i++)
	{
		val[i] = input.readInt();
		idx[i] = i;
	}

	sort(idx, idx + N, mysort);

	int i = 0, count = 0;
	while(i != N)
	{
		int curr_indx = idx[i];
		int curr_min = val[curr_indx];
		count++; i++;
		while(i < N && idx[i] < curr_indx + K && val[idx[i]] == curr_min)
			i++;
	}

	output(count, "\n");

	return 0;
}