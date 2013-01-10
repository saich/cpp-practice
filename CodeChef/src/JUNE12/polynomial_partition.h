#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <vector>
#include <map>

// TIME LIMIT EXCEEDED!

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

double readTime() {
	return double(clock()) / CLOCKS_PER_SEC;
}

INPUT input;
OUTPUT output;

const int M_MAX = 400;
const int N_MAX = 800;

const int MOD = 1000000007;

int C[11];

int T, M, N, X, D;

int P_cache[N_MAX + 1];

int cache[M_MAX + 1][N_MAX + 1];

ull P(int multiplier)
{
	if(multiplier == 0)
		return C[0];

	if(P_cache[multiplier] != -1)
		return P_cache[multiplier];

//	double start = double(clock());
	int x = (multiplier * static_cast<ull>(X)) % MOD;

	// TODO: cache the powers of X... & then carefully multiply with powers of multiplier...

	ull res = 0;
	ull product = 1;
	for(int i = 0; i <= D; i++) {
		res += ((C[i] * product) % MOD);
		product = (product * x) % MOD;
		res %= MOD;
	}

	P_cache[multiplier] = res;

	//cout << "P: " << multiplier << "=>" << double(clock()) - start << "," << res << endl;
	return res;
}

int f(int M, int N)
{
	if(N == 0) return 1;
	if(M < 1) return 0;

	// use cache here based on (M,N)
	if(cache[M][N] != -1)
		return cache[M][N];
	
	double start = readTime();
	ull sum = 0;
	for(int i = 0; i <= N; i++)
	{
		sum += (f(M-1, N-i) * P(i)) % MOD;
	}
	sum %= MOD;
	cache[M][N] = sum;

	cout << M << "," << N << "=>" << readTime() - start << endl;
	return sum;
}

int main()
{
	double sstart = readTime();
	T = input.readInt();
	while(T--) {
		
		// Take input...
		M = input.readInt();
		N = input.readInt();
		X = input.readInt();
		D = input.readInt();

		for(int i = 0; i <= N; i++)
			P_cache[i] = -1;
		
		for(int i = 0; i <= M; i++)
		{
			for(int j = 0; j <= N; j++)
				cache[i][j] = -1;
		}

		for(int i = 0; i <= D; i++)
			C[i] = input.readInt();

		output(f(M,N), "\n");
	}
	cout << readTime() - sstart << endl;

	return 0;
}

