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

double minimum_distance(vector<int> x, vector<int> y) {
  double result = 0.;
  //write your code here
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
