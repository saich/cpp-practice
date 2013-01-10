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

ull brute_force(int N) {
	vector<int> vec(N);
	ull sum = 0;
	vec[0] = 1;
	for(size_t i = 1; i < N; i++) {
		vec[i] = i+1;
		sum += ((i+1) * i);
	}
	ull max_sum = sum;
	while( next_permutation(vec.begin(), vec.end()) ) {
		sum = 0;
		for(size_t i = 1; i < N; i++) {
			sum += (vec[i] * vec[i-1]);
		}
		if(sum > max_sum)
			max_sum = sum;
	}
	return max_sum;

	// calculate sum...
}

const int N_MAX = 200000;
int data[N_MAX];
int main()
{
	//int T = input.readInt();
	int T = N_MAX;
	int N = 1;
	while(T--) {

		cout << "testing: " << N << endl;
		//int N = input.readInt();
		// Fill the array...
		for(int i = 0; i < N/2; i++) {
			data[i] = i * 2 + 1;
			data[N-1-i] = (i + 1) * 2;
		}
		if(N % 2 == 1)
			data[N/2] = N;
		
		ull sum = 0;
		// calculate the product
		for(int i = 0; i < N - 1; i++) {
			sum += ((ull)data[i] * (ull)data[i+1]);
		}

		ull brute = brute_force(N);
		if(brute != sum) {
			cout << N << endl;
		}

		N++;
		//output(sum, "\n");
	}
	return 0;
}