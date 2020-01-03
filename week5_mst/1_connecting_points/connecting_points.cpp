#include <algorithm>
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using std::vector;

class node{
  public:
    int x;
    int y;
    int parent;
    int rank;

    node(int x, int y, int parent = -1, int rank = 0){
      this->x = x;
      this->y = y;
      this->parent = parent;
      this->rank = rank;
    }
};

class edge{
  public:
    int u;
    int v;
    double weight;

    edge(int u, int v, double weight){
      this->u = u;
      this->v = v;
      this->weight = weight;
    }

};

double get_weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

void make_set(vector<node> &nodes, vector<int> &x, vector<int> &y){
  for(int i=0; i<x.size(); i++){
    nodes.push_back(node(x[i], y[i], i));
  }
}

void make_edges(vector<edge> &edges, vector<int> &x, vector<int> &y){
	for(int i=0; i<x.size(); i++){
		for(int j=i+1; j<x.size(); j++){
			edges.push_back(edge(i, j, get_weight(x[i], y[i], x[j], y[j])));
		}
	}
}

bool cmp(edge a, edge b) {
  return a.weight < b.weight;
}

int find(int i, vector<node> &nodes) {
  if (i != nodes[i].parent) {						// If the parent of the node is not equal to itself then keep going recursively
    nodes[i].parent = find(nodes[i].parent, nodes);	// Change the parent to directly the parent node so that intermediate steps are eliminated
  }
  return nodes[i].parent;	
}

void Union(int u, int v, vector<node> &nodes) {		// Merging the two nodes in 1 set
  int r1 = find(u, nodes);
  int r2 = find(v, nodes);
  if (r1 != r2) {	
    if (nodes[r1].rank > nodes[r2].rank) {			// Checking the rank of parent of each node and attaching the node
      nodes[r2].parent = r1;						// under the one with greater rank
    } 
	else {
      nodes[r1].parent = r2;
      if (nodes[r1].rank == nodes[r2].rank) {		// If the rank of boith is equal then attach under any node and increase its rank
        nodes[r2].rank++;
      }
    }
  }
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  vector<node> nodes;
  vector<edge> edges;
  make_set(nodes, x, y);		// Creating the Disjoint set
  make_edges(edges, x, y);		// Creating the edges of unidirected graph
  std::sort(edges.begin(), edges.end(), cmp);	// Sorting the edges in increasing order

  for(edge edge: edges){		// Iterating over each edge for Kruskal's algorithm
	  if(find(edge.u, nodes) != find(edge.v, nodes)){	// If two nodes are not in same set 
		  result += edge.weight;						// Add the weight of the edge to the result
		  Union(edge.u, edge.v, nodes);					// Merge the two nodes so that they are in same set now.
	  }
  }
  return result;
} 

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n), y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::setprecision(10) << minimum_distance(x, y) << std::endl;
}
