#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <vector>
#include <map>
#include<string.h>

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// scanfs
#define SUL(x) scanf("%lu", &x)
#define SLL(x) scanf("%lld", &x)
#define SULL(x) scanf("%llu", &x)


/////////////////////
////// INPUT ////////
////////////////////
class INPUT {
static const int BUFSIZE = 1<<16;
static char buffer[];
char *bufpos;
char *bufend;
void grabBuffer();
public:
INPUT() { grabBuffer(); }
bool eof() { return bufend==buffer; }
char nextChar() { return *bufpos; }
inline char readChar();
inline void skipWS();
unsigned readUnsigned();
int readInt();
};
 
char INPUT::buffer[INPUT::BUFSIZE];
 
void INPUT::grabBuffer() {
bufpos = buffer;
bufend = buffer + fread( buffer, 1,BUFSIZE,stdin);
}
 
char INPUT::readChar() {
char res = *bufpos++;
if(bufpos==bufend) grabBuffer();
return res;
}
 
inline bool myisspace(char c) { return c<=' '; }
 
void INPUT::skipWS() {
while(!eof() && myisspace(nextChar())) readChar();
}
 
unsigned INPUT::readUnsigned() {
skipWS();
unsigned res = 0;
while(!eof() && isdigit(nextChar())) {
res = 10u * res + (readChar()-'0');
}
return res;
}
 
int INPUT::readInt() {
	skipWS();
	bool neg = false;
	if(!eof() && nextChar()=='-') { neg=true; readChar(); }
	int res = static_cast<int>(readUnsigned());
	if(neg) res = -res;
	return res;
}

/////////////////////
////// OUTPUT //////
////////////////////

class OUTPUT {
static const int BUFSIZE = 1<<16;
static char buffer[];
char *bufpos;
char *BUFLIMIT;
void flushBuffer();
public:
	OUTPUT():bufpos(buffer),BUFLIMIT(buffer+BUFSIZE-100) {}
	~OUTPUT() { flushBuffer(); }
	inline void operator()(char c);
	inline void operator()(unsigned x);
	inline void operator()(int x);
	inline void operator()(unsigned long long int x);
	inline void operator()(long long int x);
	inline void operator()(const char*s);
	void operator()(const string&s) { operator()(s.c_str()); }
	template<class A,class B>
	void operator()(const A& a,const B& b) {
		operator()(a); operator()(b);
	}
	template<class A,class B,class C>
	void operator()(const A& a,const B& b,const C&c) {
		operator()(a); operator()(b); operator()(c);
	}
	template<class A,class B,class C,class D>
	void operator()(const A& a,const B& b,const C&c,const D&d) {
		operator()(a); operator()(b); operator()(c); operator()(d);
	}
	template<class A,class B,class C,class D,class E>
	void operator()(const A& a,const B& b,const C&c,const D&d,const E&e) {
		operator()(a); operator()(b); operator()(c); operator()(d); operator()(e);
	}
	template<class A,class B,class C,class D,class E,class F>
	void operator()(const A& a,const B& b,const C&c,const D&d,const E&e,const F&f) {
		operator()(a); operator()(b); operator()(c); operator()(d); operator()(e); operator()(f);
	}
};
 
char OUTPUT::buffer[OUTPUT::BUFSIZE];
 
void OUTPUT::flushBuffer() {
	char *p = buffer;
	while(p < bufpos) {
		p += fwrite( p,1, bufpos-p,stdout);
	}
	bufpos = buffer;
}
 
void OUTPUT::operator()(char c) {
	*bufpos = c;
	++bufpos;
	if(bufpos >= BUFLIMIT) flushBuffer();
}
 
void OUTPUT::operator()(unsigned x) {
	char *old = bufpos;
	do {
		*bufpos = char('0' + x % 10u);
		x /= 10u;
		++bufpos;
	} while(x);
	reverse(old, bufpos);
	if(bufpos >= BUFLIMIT) flushBuffer();
}

void OUTPUT::operator()(int x) {
	if(x<0) { operator()('-'); x = -x; }
	operator()(static_cast<unsigned>(x));
}

void OUTPUT::operator()(unsigned long long int x) {
	char *old = bufpos;
	do {
		*bufpos = char('0' + x % 10u);
		x /= 10u;
		++bufpos;
	} while(x);
	reverse(old, bufpos);
	if(bufpos >= BUFLIMIT) flushBuffer();
}

void OUTPUT::operator()(long long int x) {
	if(x<0) { operator()('-'); x = -x; }
	operator()(static_cast<unsigned long long int>(x));
}

void OUTPUT::operator()(const char*s) {
	while(*s) operator()(*s++);
}
/*
INPUT input;
OUTPUT output;
*/
int main2()
{
	int T;
	string s1, s2;
	cin >> T;
	while(T--) {
		cin >> s1 >> s2;
	}
	return 0;
}

struct node {
	int val;
	node* leftchild;
	node* rightchild;
	node(int i, node*l = NULL, node* r = NULL)
		: val(i), leftchild(l), rightchild(r)
	{}
};


// Assumes that p & q are present in the tree..
node* findLCA(node* root, node* p, node* q)
{
	// base cases...

	if(!root)
		return NULL;

	if(!p && !q) return NULL; // both the nodes are null..

	// Assuming that p & q are present in the tree, if either is null, 
	// then the non-null one has to be lowest common ancestor..
	if(p && !q) return p;	
	if(!p && q) return q;

	if(root == p || root == q) return root;

	// Try to find the given nodes (either of them) in the left & right subtrees with recursion...
	node* left = findLCA(root->leftchild, p, q);
	node* right = findLCA(root->rightchild, p , q);

	if(left && right)
		return root;

	if(left)
		return left;
	else
		return right;
}

node* convertBSTToDLL(node* root)
{
	if(!root) return NULL;

	// Do a simple in-order traversal of the tree..

	node* left = convertBSTToDLL(root->leftchild);
	
	// Since left will the minumum element in the subtree, left->leftchild = NULL already holds..

	// Go to the end of the left & add root as its next element...
	node* n = left;
	if(!left)
	{
		left = root;
	}
	else
	{
		while(n->rightchild != NULL)
			n = n->rightchild;

		n->rightchild = root;
		root->leftchild = n;
	}

	// Traverse in the right
	node* right = convertBSTToDLL(root->rightchild);

	if(right) right->leftchild = root;
	root->rightchild = right;

	return left;
}




typedef unsigned int uint;

uint reverse_bits(uint num)
{
	static_assert(sizeof(uint) == 4, "Expecting a 32-bit integer as input.. Strange compiler... :(");

	const uint num_bits = sizeof(num) * 8;
	uint reversed_num(0);
	for(uint i = 0; i < num_bits; i++)
	{
		reversed_num <<= 1;
		reversed_num |= (num & 1);
		num >>= 1;
	}
	return reversed_num;
}

typedef unsigned int uint;

std::string uintToString(uint num)
{
	if(num == 0) return "0";

	std::string str;
	while(num != 0)
	{
		char now = (num % 10) + '0';
		str = now + str;
		num /= 10;
	}
	return str;
}

std::string long2ip(uint num)
{
	static_assert(sizeof(uint) == 4, "Expecting int to be 32-bit");
	uint parts[4] = {0};
	for(size_t i = 0; i < 4; i++)
	{
		parts[i] = num & 0xFF;
		num >>= 8;
	}
	return uintToString(parts[3]) + "." + uintToString(parts[2]) + "." + uintToString(parts[1]) + "." + uintToString(parts[0]);
}


/* Handles IPv4 addresses (full address representation only..)
 * Throws in case of invalid string format..
 * Examples:
 *		"0.0.0.1" => 1
 *		"1.1.1.1" => 16843009
 *		"255.0.234.456" => exception
 *		"255.255.255.255" => 4294967295
 *		"255.0.234.156" => 4278250140
 *		"127.0.0.1" => 2130706433
 */

uint ip2long(const std::string& ip)
{
	size_t partIndex(0);
	bool bPartValid = false;
	uint parts[4] = {0};

	bool bSuccess = true;
	for(std::string::const_iterator it = ip.begin(); it != ip.end(); ++it)
	{
		if(*it <= '9' && *it >= '0')
		{
			bPartValid = true;
			parts[partIndex] = parts[partIndex] * 10 + (*it - '0');
		}
		else if(*it == '.' && bPartValid && partIndex < 3 && parts[partIndex] < 256)
		{
			partIndex++;
			bPartValid = false;
		}
		else
		{
			// error..
			bSuccess = false;
			break;
		}
	}

	if(!bSuccess || !bPartValid || partIndex != 3 || parts[partIndex] > 255)
	{
		// In case of ill-formatted strings, throw exception...
		// We cannot return o because '0.0.0.0' is a valid IP address..
		return 0;throw std::exception("Invalid IP-address");
	}

	uint result(0);
	// calculate the result..
	for(size_t i = 0; i < 4; i++)
	{
		result = (result * 256) + parts[i];
	}
	return result;
}

int main3()
{
	//node root(4, new node(2, new node(1), new node(3)), new node(5));
	//node* t = convertBSTToDLL(&root);

	std::cout << long2ip(0) << std::endl;
	std::cout << long2ip(255) << std::endl;
	std::cout << long2ip(36535) << std::endl;
	std::cout << long2ip(976655) << std::endl;
	std::cout << long2ip(458350350) << std::endl;

	std::cout << ip2long("0.0..1") << std::endl;
	std::cout << ip2long(".1.1.1.1") << std::endl;
	std::cout << ip2long("255.0.234.456") << std::endl;
	std::cout << ip2long("255.255.255.255") << std::endl;
	std::cout << ip2long("255.0.234.156") << std::endl;
	std::cout << ip2long("127.0.0.1") << std::endl;
	std::cout << ip2long("192.168.456.3") << std::endl;



	unsigned int a = reverse_bits(0);
	a = reverse_bits(1);
	a = reverse_bits(32);
	a = reverse_bits(10);
	return 0;
}

/*

bool cycle_exists(node* node)
{
	if(!node) return false; // EMpty list.. cant have a cycle..

	node* tortoise(node), hare(node->next);

	// hare moves faster than tortoise.. and they will never be at same position (unless they are running in a loop)

	// If there is no loop, hare goes upto the end of the list and then the race ends..
	// If there is a loop, the race will never end, and at a stage, tortoise & hare will cross each other..
	while(tortoise && hare && tortoise != hare && hare->next != NULL)
	{
		// our hare is twice as fast as tortoise...
		tortoise = tortoise->next;
		hare = hare->next->next;
	}
	return (tortoise == hare);
}
*/

typedef unsigned long long ull;

// Calculate the number of ways to choose 'r' objects from the set of 'n' objects.
ull C(ull n, ull r)
{
	if(n < r) return 0;
	if(n == r) return 1;

    ull result(1);

    for (ull i = r + 1; i <= n; i++)
        result *= i;

    for (ull i = n - r; i > 1; i--)
        result /= i;

    return result;
}

// Count the siginificant bits in the given number...
// Siginificant bits => No. of bits in the number, without the starting '0' bits.
inline size_t msb_count(ull n)
{
	size_t count(0);
	while(n != 0)
	{
		count++;
		n >>= 1;
	}
	return count;
}

// Identifies the number numbers in [0,n] with number-of-set-bits = 'bits'
ull count_recursion(ull n, size_t bits, size_t msb)
{
	if(bits == 0) return 1;
	if(n == 0) return 0;

	if(msb < bits)
		return 0;

	ull next_num = n - (1ULL << (msb-1)); // Remove the highest set bit..
	return C(msb - 1, bits) + count_recursion( next_num, bits - 1, msb_count(next_num) );
}

// Calculates the number of numbers in [0, num] with the condition that the number of '1'-bits
// lof the number lies in the vector fib_nums..
ull fibonnaci_bits_upto(ull num, const std::vector<size_t>& fib_nums)
{
	size_t msb = msb_count(num);
	ull count(0);
	for(size_t i = 0, end = fib_nums.size(); i < end; i++)
	{
		if(msb < fib_nums[i])
			break;
		count += count_recursion(num, fib_nums[i], msb);
	}
	return count;
}

// Identifies if the number 'num' satifies the fibonaci-bit-count condition..
bool has_fibonacci_bits(ull num, const std::vector<size_t>& fib_nums)
{
	// count bits in num..
	size_t count(0);
	while(num != 0)
	{
		num &= (num-1);
		count++;
	}
	return std::binary_search(fib_nums.begin(), fib_nums.end(), count);
}

// Returns the number of elements in [A,B] with no. of bits = a fib. number
// Note that, A <= B
ull count_fibonnaci_bits(ull A, ull B)
{
	static_assert(sizeof(ull) == 8, "long long is expected to be 64-bit");

	// precompute the fibonacci numbers that are <= 64
	std::vector<size_t> fib_nums;
	fib_nums.push_back(1);
	size_t first(1), second(2);
	while(second <= 64)
	{
		std::swap(first, second);
		second += first;
		fib_nums.push_back(first);
	}

	// [0,B] - [0,A] + [A,A]
	return fibonnaci_bits_upto(B, fib_nums) - fibonnaci_bits_upto(A, fib_nums) + (has_fibonacci_bits(A, fib_nums) ? 1 : 0);
}

int main_()
{
	std::cout << count_fibonnaci_bits(15, 17) << std::endl;
	return 0;
}