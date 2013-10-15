#ifndef CONNECTEDCOMPONENTS_H_
#define CONNECTEDCOMPONENTS_H_

#include "Graph.h"
#include <vector>

// Preprocess the complete graph in O(E+V) time, so that
// component identifications can happen in O(1) time.

template <bool isUndirected = false>
class ConnectedComponents {
public:
	ConnectedComponents(const Graph<isUndirected>& G) : m_count(0) {
		m_marked.resize(G.V());
		m_id.resize(G.V());

		// Do a DFS for all vertices
		for (size_t i = 0; i < G.V(); i++) {
			if (!m_marked[i]) {
				dfs(G, i);
				m_count++;
			}
		}
	}

	/**
	 * Indicates if vertices v and w are connected.
	 */
	bool connected(size_t v, size_t w) const {return m_id[v] == m_id[w];}

	/**
	 * Number of connected components
	 */
	size_t count() const {return m_count;}

	/**
	 * Component Id for vertex v
	 */
	size_t id(size_t v) const {return m_id[v];}

private:
	std::vector<bool> m_marked;
	std::vector<size_t> m_id;
	size_t m_count;

	void dfs(const Graph<isUndirected>& G, size_t src) {
		m_marked[src] = true;
		m_id[src] = m_count;
		for (std::list::const_iterator it = G.adj(src); it != std::list::npos; ++it) {
			if(!m_marked[*it]) {
				dfs(G, *it);
			}
		}
	}
};


#endif /* CONNECTEDCOMPONENTS_H_ */
