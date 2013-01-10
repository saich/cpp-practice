#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

// Problem:	http://www.codechef.com/problems/POINTS/

#define SQUARE(x) ((x) * (x))

class Point
{
public:
	unsigned short x;
	unsigned short y;

	Point(unsigned short _x = 0, unsigned short _y = 0):x(_x), y(_y) {}

	inline double DistanceTo(const Point& p)
	{
		return std::sqrt( static_cast<double>(SQUARE(x - p.x) + SQUARE(y - p.y)) );
	}
};

// Got compilation error, if this was a member function of the class
bool operator<(const Point& p1, const Point& p2)
{
	if (p1.x < p2.x) 
		return true;
	else if(p1.x > p2.x) 
		return false;
	else 
		return p1.y > p2.y;
}

void TravellingDistance()
{
	unsigned short t; // No. of testcases
	scanf("%hu", &t);
	unsigned long n; // n must be long since we require more than 16 bits. size(long) >= 4 & sizeof(int) >= 2, as per standard 
	for(unsigned short i = 0; i < t; i++)
	{
		scanf("%lu", &n);
		std::vector<Point> points(n);

		// take i/p
		for(unsigned long i = 0; i < n; i++)
		{
			scanf("%hu%hu", &points[i].x, &points[i].y);
		}

		// sort all the points
		std::sort(points.begin(), points.end());

		// calculate the distance
		double dist = 0;
		for(unsigned long i = 0; i < n - 1; i++)
		{
			dist += points[i].DistanceTo( points[i + 1] );
		}

		// output
		std::cout.setf(std::ios::fixed);
		std::cout << std::setprecision(2) << dist << std::endl;
	}
}