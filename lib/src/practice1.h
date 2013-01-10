#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <vector>
#include <map>
#include<string.h>

/**
 * LOGIC:
 *		A simple max-flow algorithm with supersink & supersource, which connects
 *		to the multiple sinks & sources respectievely with infinite flow rate
 */

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

// scanfs
#define SUL(x) scanf("%lu", &x)
#define SLL(x) scanf("%lld", &x)
#define SULL(x) scanf("%llu", &x)

const int N_MAX = 1001;
const int oo = 100000;

int mat[N_MAX + 2][N_MAX + 2] = {0};
int flow_network[N_MAX + 2][N_MAX + 2] = {0};

#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX_NODES N_MAX+2

int n;	// Number of vertices
int color[MAX_NODES]; // needed for breadth-first search
int pred[MAX_NODES];  // array to store augmenting path

// Queue for BFS...
int head,tail;
int q[MAX_NODES + 2];

void enqueue (int x) {
	q[tail] = x;
	tail++;
	color[x] = GRAY;
}

int dequeue() {
	int x = q[head];
	head++;
	color[x] = BLACK;
	return x;
}

// Breadth-First Search for an augmenting path
int bfs (int start, int target) {
	int u,v;
	for (u = 0; u < n; u++) {
		color[u] = WHITE;
	}

	head = tail = 0;
	enqueue(start);
	pred[start] = -1;
	while (head != tail) {
		u = dequeue();
		// Search all adjacent white nodes v. If the capacity
		// from u to v in the residual network is positive,
		// enqueue v.
		for (v = 0; v < n; v++) {
			if (color[v] == WHITE && mat[u][v] - flow_network[u][v] > 0) {
				enqueue(v);
				pred[v] = u;
			}
		}
	}
	// If the color of the target node is black now,
	// it means that we reached it.
	return color[target] == BLACK;
}

// Ford-Fulkerson Algorithm

int max_flow (int source, int sink) {
	int i,j,u;
	// Initialize empty flow.
	int max_flow = 0;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			flow_network[i][j] = 0;
		}
	}
	// While there exists an augmenting path,
	// increment the flow along this path.
	while (bfs(source,sink)) {
		// Determine the amount by which we can increment the flow.
		int increment = oo;
		for (u=n-1; pred[u]>=0; u=pred[u]) {
			increment = min(increment,mat[pred[u]][u]-flow_network[pred[u]][u]);
		}
		// Now increment the flow.
		for (u=n-1; pred[u]>=0; u=pred[u]) {
			flow_network[pred[u]][u] += increment;
			flow_network[u][pred[u]] -= increment;
		}
		max_flow += increment;
	}
	// No augmenting path anymore. We are done.
	return max_flow;
}

int main()
{
	int s,t,r,h;
	cin >> n >> s >> t >> r >> h;

	// [n] is supersource...
	// [n+1] is supersink...

	// Read source points..
	int vertex;
	for(int i = 0; i < s; i++)
	{
		cin >> vertex;
		mat[n][vertex] = oo; // supersource-to-source
	}

	// Read the rescue points..
	for(int i = 0; i < t; i++)
	{
		cin >> vertex;
		mat[vertex][n+1] = oo; // sink-to-supersink
	}

	// Read in the roads..
	int l1, l2, capacity;
	for(int i = 0; i < r; i++)
	{
		cin >> l1 >> l2 >> capacity;
		mat[l1][l2] = capacity;
	}

	n = n+2; // Aditional two nodes...

	cout << h * max_flow(n-2, n-1); // flow is per hour...
	return 0;
}