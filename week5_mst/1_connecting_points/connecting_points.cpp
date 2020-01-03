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

double get_weight(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

bool cmp(edge a, edge b) {
  return a.weight < b.weight;
}

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
  vector<node> nodes;
  vector<edge> edges;
  make_set(nodes, x, y);
  make_edges(edges, x, y);
  std::sort(edges.begin(), edges.end(), cmp);
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
