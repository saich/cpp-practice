#include <iostream>
#include <algorithm>
#include <time.h>
typedef unsigned long long ull;
 
// scanfs
#define SUL(x) scanf("%lu", &x)
#define SLL(x) scanf("%ll", &x)
#define SULL(x) scanf("%llu", &x)

/////////// BEGIN BRUTE FORCE ///////////////////

int count_digits(ull M, int digit)
{
	int count(0);
	while(M != 0)
	{
		if(M % 10 == digit) count++;
		M /= 10;
	}
	return count;
}
 
int brute_force(ull M, ull N)
{
	int fours, sevens, max(0);
	for(ull i = M; i <= N; i++)
	{
		fours = count_digits(i, 4);
		sevens = count_digits(i, 7);
		if(fours * sevens > max)
		max = fours * sevens;
	}
	return max;
}

/////////// END BRUTE FORCE ///////////////////

int product(int fours, int sevens, int any) {
	int diff = std::abs(fours - sevens);
	if(diff <= any) {
		int sum = fours + sevens + any;
		return (sum / 2) * (sum - sum / 2);
	} else {
		return (fours < sevens)
			? (fours + any) * sevens
			: fours * (sevens + any);
	}
}
 
int lesser_than(int r[], int index, int fours, int sevens)
{
	if(index < 0)
		return product(fours, sevens, 0);
	
	int product2(0), product4(0);
	 
	if(r[index] > 7)
		return product(fours, sevens, 1 + index);
	else if(r[index] > 4)
		product2 = product(fours + 1, sevens, index);
	else if(r[index] > 0)
		product2 = product(fours, sevens, index);
	 
	// EQUAL...
	product4 = lesser_than(r, index - 1, fours + (r[index] == 4 ? 1 : 0), sevens + (r[index] == 7 ? 1 : 0));
	 
	return std::max(product2, product4);
}
 
int greater_than(int l[], int index, int fours, int sevens)
{
	if(index < 0)
		return product(fours, sevens, 0);
	int product2(0), product4(0);
	 
	if(l[index] < 4)
		return product(fours, sevens, 1 + index);
	else if(l[index] < 7)
		product2 = product(fours, sevens + 1, index);
	else if(l[index] < 9)
		product2 = product(fours, sevens, index);
	 
	// EQUAL...
	product4 = greater_than(l, index - 1, fours + (l[index] == 4 ? 1 : 0), sevens + (l[index] == 7 ? 1 : 0));
	 
	return std::max(product2 , product4);
}
 
int solve(ull L, ull R)
{
	int l[19] = {0}, r[19] = {0}; // 10 ^ 18 have (18 + 1) = 19 digits..
	
	// Get all individual digits in L & R, with least-significant digit at 0-index..
	int l_index(0), r_index(0);
	 
	while(L != 0) {
		l[l_index++] = L % 10;
		L /= 10;
	}
	 
	while(R != 0) {
		r[r_index++] = R % 10;
		R /= 10;
	}
	 
	int index = r_index - 1;
	 
	// Filter out the starting common digits (most siginificant ones) in L & R...
	int fours(0), sevens(0);
	while(index >= 0 && r[index] == l[index])
	{
		if(l[index] == 4)
			fours++;
		else if(r[index] == 7)
			sevens++;
		index--;
	}
	 
	// Damn... L = R...
	if(index < 0) {
		return product(fours, sevens, 0);
	}
	 
	int product1(0), product2(0), product3(0), product4(0), product5(0);
	 
	bool a = false, b = false;
	if(l[index] < 4 && r[index] > 4)
	{
		a = true;
		product1 = product(fours + 1, sevens, index);
	}
	 
	if(l[index] < 7 && r[index] > 7)
	{
		b = true;
		product2 = product(fours, sevens + 1, index);
	}
	if(a && b)
		return std::max(product1, product2);
	 
	if(!a && !b && r[index] - l[index] > 1)
		product3 = product(fours, sevens, index);
	 
	// LEFT EQUAL - The case where X[index] = L[index]
	product4 = greater_than(l, index - 1, fours + (l[index] == 4 ? 1 : 0), sevens + (l[index] == 7 ? 1 : 0));
	// RIGHT EQUAL - The case where X[index] = R[index]
	product5 = lesser_than(r, index - 1, fours + (r[index] == 4 ? 1 : 0), sevens + (r[index] == 7 ? 1 : 0));
	 
	int max_product = std::max(product1, std::max(std::max(std::max(product2, product3), product4), product5));
	return max_product;
}
 
int main()
{
	int T;
	ull L, R;
	scanf("%d", &T);
	// T = 30000;srand(time(NULL));
	while(T--) {
		SULL(L); SULL(R);
		//L = 1 + rand(); R = L + rand();
		//std::cout << L << "," << R << std::endl;
		int sol = solve(L, R);
		//int brute = brute_force(L, R);
		//if(sol != brute)
		//	std::cout << "ERROR:" << L << R << std::endl;
		printf("%d\n", sol);
	}
	return 0;
} 