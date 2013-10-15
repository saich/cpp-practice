#ifndef GRAPH_H_
#define GRAPH_H_

class graph {
};

template<typename Vertex>
struct edge_base {
	inline edge_base() {}
	inline edge_base(Vertex source, Vertex target) :
			m_source(source), m_target(target) {}
	Vertex m_source;
	Vertex m_target;
};

enum default_color_type { white_color, gray_color, green_color, red_color, black_color };

  template <class ColorValue>
  struct color_traits {
    static default_color_type white() { return white_color; }
    static default_color_type gray() { return gray_color; }
    static default_color_type green() { return green_color; }
    static default_color_type red() { return red_color; }
    static default_color_type black() { return black_color; }
  };

#endif /* GRAPH_H_ */
