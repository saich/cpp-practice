#include <iostream>

// Problem:		http://www.codechef.com/problems/SUMTRIAN/
// Tutorial:	http://www.codechef.com/wiki/recursion-sums-triangle

typedef unsigned short	item_t;		// type for each item in the traingle
typedef unsigned int	result_t;	// type for the final result
typedef unsigned short	line_t;		// type for no. of lines in the triangle
typedef unsigned int	testcount_t;// type for no. of i/p test cases

inline size_t GetItemIndex(line_t row, line_t col)
{
	// Retuen the array index of item at (row, col)
	return row * (row + 1) / 2 + col;
}

result_t PartialSum(line_t row, line_t col, line_t lines, item_t* input, item_t* cache)
{
	// row < lines, col < lines
	if( !(row < lines && col < lines) )
		return 0;
	size_t index =  GetItemIndex(row, col);

	if(cache[index] != 0)
		return cache[index];

	result_t a = PartialSum(row + 1, col, lines, input, cache);
	result_t b = PartialSum(row + 1, col + 1, lines, input,cache);
	
	result_t ret = input[index] + std::max(a, b);
	cache[index] = ret;
	return ret;
}

void MaxSumTriangle()
{
	testcount_t n;
	scanf("%u", &n);
	//std::cin >> n;
	for(testcount_t i = 0; i < n; i++)
	{
		line_t lines; // lines  < 100
		scanf("%hu", &lines);
		//std::cin >> lines;
		// n lines contain 1 + 2 + .... + n = n * (n + 1) / 2 entries exactly.
		size_t count = lines * (lines + 1) / 2;
		item_t *ip = new item_t[count];
		item_t *cache = new item_t[count];
		// Take input
		for(size_t i = 0; i < count; i++)
		{
			scanf("%hu", &ip[i]);
			//std::cin >> ip[i];
			cache[i] = 0; // initialize all items in cache
		}
		printf("%u\n", PartialSum(0, 0, lines, ip, cache));
		//std::cout << PartialSum(0, 0, lines, ip, cache) << std::endl;
		delete[] ip;
		delete[] cache;
	}
}