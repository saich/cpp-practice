#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>

// UNSOLVED!!

// https://www.interviewstreet.com/challenges/dashboard/#problem/4e14b2cc47f78

// @see http://en.wikipedia.org/wiki/Chebyshev_distance
// @see http://en.wikipedia.org/wiki/Geometric_median
// @see http://stackoverflow.com/questions/7027753/minimum-sum-of-all-travel-times

typedef unsigned long long ull;
class Point {
public:	
	int x;
	int y;
};

typedef std::vector<Point> LST;

// Distance b/w two points
ull dist(const Point& a, const Point& b)
{
	return std::max(std::abs(a.x - b.x), std::abs(a.y - b.y));
}

// Calculate the sum of distances..
ull sum(const Point& p, const LST& list)
{
	ull sum(0);
	for(size_t i = 0, j = list.size(); i < j; ++i)
	{
		sum += dist(p, list[i]);
	}
	return sum;
}

// Find the point inside list that is closest to p..
size_t closest(const Point& p, const LST& list)
{
	size_t ret = 0;
	ull lowest_dist = dist(p, list[0]);
	ull d;
	for(size_t i = 1, j = list.size(); i < j; ++i)
	{
		d = dist(p, list[i]);
		if(d < lowest_dist)
		{
			lowest_dist = d;
			ret = i;
		}
	}
	return ret;
}

int main()
{
	int N;
	scanf("%d", &N);

	LST list(N); 
	for(int i = 0; i < N; ++i)
	{
		scanf("%d%d", &(list[i].x), &(list[i].y));
	}

	// Get the Geometric Mean
	ull x(0), y(0);
	for(int i = 0; i < N; ++i)
	{
		x += list[i].x;
		y += list[i].y;
	}

	Point mean;
	mean.x = x / N;
	mean.y = y / N;

	for(int q = 0; q < 25; ++q) {
		// TODO: Approximate the geometric median
		double deno(0.0), numo1(0.0), numo2(0.0);
		for(size_t i = 0; i < N; ++i)
		{
			ull d = dist(mean, list[i]);
			deno += (1.0 / d);
			numo1 += (static_cast<double>(list[i].x) / d);
			numo2 += (static_cast<double>(list[i].y) / d);
		}

		mean.x = (numo1 / deno);
		mean.y = (numo2 / deno);
	}


	size_t idx = closest(mean, list);

	// TODO: Calculate the sum of distances from median..
	std::cout << sum(list[idx], list) << std::endl;
	return 0;
}