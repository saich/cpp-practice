//////////////////////
// THANKS TO ANIL ////
//////////////////////
#include "template.h"
int bit_pos(ull num)
{
	int pos(-1);
	while(num != 0)
	{
		num >>= 1;
		pos++;
	}
	return pos; // range will be [0, 63]
}

ull nums[100005];
int data[70] = {0};
int n;

bool brute_force()
{
	// brute force
	for(int i1 = 0; i1 < n; i1++)
	{
		for(int i2 = i1 +1; i2 < n; i2++)
		{
			for(int i3 = i2+1; i3 < n; i3++)
			{
				for(int i4 = i3+1; i4 < n; i4++)
				{
					if((nums[i1] ^ nums[i2] ^ nums[i3] ^ nums[i4]) == 0)
					{
						/*
						cout << "Found wrong answer for input: ";
						for(int i = 0; i < n; i++)
						{
							cout << nums[i] << " ";
						}
						cout << endl;

						
						cout << "Answer is: " << nums[i1] << " " << nums[i2] << " " << nums[i3] << " " << nums[i4] << endl;
						*/
						return true;
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	n = input.readInt();
	bool bConsecutive = false;
	int second_index_consecutive = -1;
	for(int i = 0; i < n; i++)
	{
		nums[i] = input.readULL();
	}

	bool bFound = false; //n > 67 ? true : brute_force();
	
	// Atleast two bit positions will repeat twice with no overlap or a triplet will be present...
	if(n > 67)
	{
		bFound = true;
	}
	else
	{
		for(int i = 0; i < n-1; i++)
		{
			int pos = bit_pos(nums[i] ^ nums[i+1]); // xor of adjacent numbers (which will be a power of 2)
			if(data[pos] == 0)
			{
				// seeing it first-time..
				data[pos] = i + 1; // i+1 so that index 0 will be invalid value..
			}
			else if(i > data[pos])
			{
				// found a same number at a non-adjacent position..
				bFound = true;
				break;
			}
			else if(i == data[pos])
			{
				// a consecutive same number is found... meaning 1st num xor 3rd number = 0
				if(bConsecutive)
				{
					if(i - second_index_consecutive > 2)
					{
						bFound = true;
						break;
					}
				}
				else
				{
					bConsecutive = true;
					second_index_consecutive = i;
				}
			}
		}
	}
	output(bFound ? "Yes" : "No", "\n");
	return 0;
}
