#include "template.h"

typedef pair<int, int> IntPair; // first is value, second is probability percentage..

ull merge2(vector<IntPair>& data, size_t left, size_t mid, size_t right)
{
	// [left, mid] is sorted, [mid+1, right] is sorted
	
	// New vector of size: (right - left + 1)
	vector<IntPair> dest(right - left + 1);

	size_t i(left), j(mid+1), k(0); // i -> left array, j-> right array, k->destination index

	ull sum(0), inversions(0);
	while(i <= mid && j <= right)
	{
		if(data[i].first <= data[j].first)
		{
			dest[k++] = data[i];
			inversions += (sum * data[i].second);
			i++;
		}
		else
		{
			dest[k++] = data[j];
			sum += data[j].second;
			j++;
		}
	}

	while(i <= mid)
	{
		dest[k++] = data[i];
		inversions += (sum * data[i].second);
		i++;
	}

	while(j <= right)
	{
		dest[k++] = data[j++];
	}

	// copy destination to the original vector...
	for(size_t i = left, idx = 0; i <= right; i++,idx++)
	{
		data[i] = dest[idx];
	}

	return inversions;
}

// [left, right] => right is the right index, not the element past right..
ull sort_count(vector<IntPair>& data, size_t left, size_t right)
{
	ull count(0);
	if(left < right)
	{
		size_t mid = (left + right) / 2;
		ull r1 = sort_count(data, left, mid);
		//cout << "<" << left << "," << mid << "> = " << r1 << endl; 
		ull r2 = sort_count(data, mid + 1, right);
		//cout << "<" << mid+1 << "," << right << "> = " << r2 << endl; 
		ull r3 = merge2(data, left, mid, right);
		//cout << "Merge<" << left << "," << mid << "," << right << "> = " << r3 << endl; 
		count = r1 + r2 + r3;
	}
	return count;
}

int main()
{
	cout.setf(ios::fixed,ios::floatfield);
	cout.precision(4);

	int T = input.readInt();
	while(T--) {
		int n = input.readInt(), d = input.readInt();
		vector<IntPair> mixed(2 * n);
		
		// read in array...
		for(int i = 0; i < n; i++)
		{
			int temp = input.readInt();
			mixed[2 * i].first = temp;
			mixed[2 * i + 1].first = temp + d;
		}

		// read in probabilities...
		for(int i = 0; i < n; i++)
		{
			int temp = input.readInt();
			mixed[2 * i].second = 100-temp;
			mixed[2 * i + 1].second = temp;
		}

		// count inversions using modified merge sort...
		cout << sort_count(mixed, 0, mixed.size() - 1) / 1e4 << endl;
	}
	return 0;
}