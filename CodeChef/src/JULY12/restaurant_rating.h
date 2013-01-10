#include "template.h"

int main()
{
	int N = input.readInt(), opt, val;

	greater<int> min_heap_comp;

	vector<int> left_heap, right_heap; // left is max-heap, right is min-heap...

	left_heap.reserve(166667);
	right_heap.reserve(83334);

	int ratings_count(0);
	for(int i = 0; i < N; i++)
	{
		opt = input.readInt();
		if(opt == 1)
		{
			val = input.readInt();
			//cout << "inserting " << val << endl;
			if((ratings_count+1)/3 == ratings_count/3)
			{
				if(!right_heap.empty() && val > right_heap[0])
				{
					// This new item should go into right_heap... Replace the least element there...
					pop_heap(right_heap.begin(), right_heap.end(), min_heap_comp);
					swap(val, right_heap[right_heap.size() - 1]);
					push_heap(right_heap.begin(), right_heap.end(), min_heap_comp);
				}
				// push val to left_heap...
				left_heap.push_back(val);
				push_heap(left_heap.begin(), left_heap.end());
			}
			else
			{
			//	cout << "increase right heap's size\n"; 
				if(val < left_heap[0])
				{
					pop_heap(left_heap.begin(), left_heap.end());
					swap(val, left_heap[left_heap.size() - 1]);
					push_heap(left_heap.begin(), left_heap.end());
				}

				// Add val to right_heap...
				right_heap.push_back(val);
				push_heap(right_heap.begin(), right_heap.end(), min_heap_comp);
			}

			ratings_count++;
		}
		else if(opt == 2)
		{
			if(right_heap.empty())
				output("No reviews yet", "\n");
			else
				output(right_heap[0], "\n");
		}
	}
	return 0;
}