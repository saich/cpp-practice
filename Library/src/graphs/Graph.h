#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <vector>
#include <list>
#include <exception>
#include <sstream>

/*
 * Undirected.
 * Adjacency List Representation (supports self-loops, parallel edges)
 * Vertices are represented as 0 to V - 1 (Use symbol tables for names to indices)
 */
template <bool isUndirected = false>
class Graph {
public:
	Graph(size_t V)
	: m_V(V), m_E(0) {
		m_adj.resize(V);
	};

	void addEdge(size_t v, size_t w) {
		if (v >= V() || w >= V()) throw std::exception("Vertex out of bounds");

		m_E++;
		m_adj[v].push_back(w);

		if (isUndirected) {
			m_adj[w].push_back(v);
		}
	}

	size_t V() const { return m_V; }
	size_t E() const { return m_E; }

	std::list::const_iterator adj(size_t v) const {
		return m_adj[v].begin();
	}

	Graph<isUndirected> reverse() {
		Graph<isUndirected> G(m_V);
		for (size_t i = 0; i < m_V; i++) {
			for(std::list::const_iterator it = adj(i); it != std::list::npos; ++it) {
				G.addEdge(*it, i);
			}
		}
		return G;
	}

	std::string toString() const {
		std::stringstream ss;
		ss << m_V << " vertices, " << m_E << " edges" << std::endl;
		for (size_t v = 0; v < m_V; v++) {
			ss << v << ": ";
			for (std::list::const_iterator it = adj(v); it != std::list::npos; ++it) {
				ss << *it << " ";
			}
			ss << std::endl;
		}
		return ss.str();
	}

private:
	std::vector< std::list<size_t> > m_adj;
	const size_t m_V;
	size_t m_E;
};

typedef Graph<true> UndirectedGraph;
typedef Graph<false> DirectedGraph;

#endif /* GRAPH_H_ */
