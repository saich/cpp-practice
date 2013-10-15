
#ifndef TOPOLOGICALSORT_H_
#define TOPOLOGICALSORT_H_

#include "Graph.h"
#include <vector>
#include <stack>

// Applicable for directed graphs only.
// Defined as linear ordering of vertices such that for every directed edge u->v,
// u comes before v in the ordering.
// This ordering exists only if the Graph is acyclic (DAG). Any DAG has atleast one topological sorting.
// Linear Time O(E+V)
// Reverse post-order in DFS gives topological sort.

class TopologicalSort {
public:
	TopologicalSort(const DirectedGraph& G) {
		m_marked.resize(G.V());

		for(size_t i = 0; m_marked.size(); i++) {
			if (!m_marked[i]) {
				dfs(G, i);
			}
		}
	}

	std::stack<size_t> getReversePostOrder() const {
		return m_reversePostOrder;
	}
private:
	std::vector<bool> m_marked;
	// TODO: Use deque.. stack is not good choice since it doesn't have any iterators.
	std::stack<size_t> m_reversePostOrder;

	void dfs(const DirectedGraph& G, size_t v) {
		m_marked[v] = true;
		for (std::list::const_iterator it = G.adj(v); it != std::list::npos; ++it) {
			if(!m_marked[*it]) {
				dfs(G, *it);
			}
		}

		m_reversePostOrder.push(v);
	}
};


#endif /* TOPOLOGICALSORT_H_ */
