#ifndef DFS_H_
#define DFS_H_

#include "Graph.h"
#include <vector>
#include <stack>

template <bool isUndirected = false>
class DFS {
public:
	DFS(Graph<isUndirected> G, size_t src): m_src(src), m_count(0) {
		m_marked.resize(G.V()); // By default, sets all to false
		m_edges.resize(G.V());
		dfs(G, src);
	}

	size_t count() const  {return m_count;}
	bool hasPathTo(size_t v) const { return m_marked[v];}

	std::stack<size_t> pathTo(size_t v) {
		std::stack<size_t> path;
		if(!hasPathTo(v)) {
			return path;
		}

		size_t i;
		for(i = v; i != m_src; i = m_edges[i]) {
			path.push(i);
		}
		path.push(i);
		return path;
	}

private:
	std::vector<bool> m_marked;
	size_t m_src; // source vertex
	std::vector<size_t> m_edges; // m_edges[v] = last edge on src->v path.
	size_t m_count; // Number of vertices connected to source vertex, including the source.

	void dfs(Graph<isUndirected> G, size_t v) {
		m_count++;
		m_marked[v] = true;
		for (std::list::const_iterator it = G.adj(v); it != std::list::npos; ++it) {
			if(!m_marked[*it]) {
				m_edges[*it] = v;
				dfs(G, *it);
			}
		}
	}
};

#endif
