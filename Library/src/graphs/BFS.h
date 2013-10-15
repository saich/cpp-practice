#ifndef BFS_H_
#define BFS_H_

#include "Graph.h"
#include <vector>
#include <stack>
#include <queue>
#include <limits>

// 1. BFS computes shortest paths (fewer number of of edges) from source vertex s
// 	to all other vertices in O(E + V)
// 2. Multiple-sources shortest paths: Shortest path from any vertex of the source vertices,
//	Initialize the queue with all source vertices.

template <bool isUndirected = false>
class BFS {
public:
	// single source
	BFS(Graph<isUndirected> G, size_t src) : m_count(0) {
		m_marked.resize(G.V());
		m_edges.resize(G.V());
		m_distance.resize(G.V());

		// Initialize all distances to INFINITY
		for (size_t i = 0; i < G.V(); i++) {
			m_distance[i] = std::numeric_limits<size_t>::max();
		}

		m_src.push_back(src);
		bfs(G, m_src);
	}

	// Multiple sources
	BFS(Graph<isUndirected> G, std::vector<size_t> src) : m_count(0), m_src(src) {
		m_marked.resize(G.V());
		m_edges.resize(G.V());
		m_distance.resize(G.V());

		// Initialize all distances to INFINITY
		for (size_t i = 0; i < G.V(); i++) {
			m_distance[i] = std::numeric_limits<size_t>::max();
		}

		bfs(G, m_src);
	}

	size_t count() const  {return m_count;}
	bool hasPathTo(size_t v) const { return m_marked[v];}
	size_t distTo(size_t v) const {return m_distance[v];}

	std::stack<size_t> pathTo(size_t v) {
		std::stack<size_t> path;
		if(!hasPathTo(v)) {
			return path;
		}

		size_t i;
		for(i = v; m_distance[i] != 0; i = m_edges[i]) {
			path.push(i);
		}
		path.push(i);
		return path;
	}
private:
	std::vector<bool> m_marked;
	std::vector<size_t> m_src; // source vertices
	std::vector<size_t> m_edges; // m_edges[v] = last edge on src->v path.
	size_t m_count; // Number of vertices connected to source vertex, including the source.
	std::vector<size_t> m_distance; // Distance from source vertex to each vertices.

	void bfs(Graph<isUndirected> G, std::vector<size_t> src) {
		std::queue<size_t> q;
		for(size_t i = 0; i < src.size(); i++) {
			q.push(src[i]);
			m_distance[src[i]] = 0;
			m_marked[src[i]] = true;
			m_count++;
		}

		while (q.size()) {
			size_t w = q.front();
			q.pop();

			// Insert into queue all non-visited adjacent to w
			for (std::list::const_iterator it = G.adj(w); it != std::list::npos; ++it) {
				if (!m_marked[*it]) {
					m_marked[*it] = true;
					m_distance[*it] = m_distance[w] + 1;
					m_edges[*it] = w;
					q.push(*it);
					m_count++;
				}
			}
		}
	}
};


#endif /* BFS_H_ */
