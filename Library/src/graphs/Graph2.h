
#ifndef GRAPH2_H_
#define GRAPH2_H_

#include <string>

class WeightedEdge {
public:
	WeightedEdge(size_t from, size_t to, double w) : _from(from), _to(to), _weight(w) {}
	size_t from() const {return _from;}
	size_t to() const {return _to;}
	double weight() const {return _weight;}
	bool isDirected() const;
	std::string toString() const;

	// TODO: Add comparison operators
private:
	const size_t _to, _from;
	const double _weight;
};


#endif /* GRAPH2_H_ */
