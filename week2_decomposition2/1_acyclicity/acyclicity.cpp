#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > adj, int vertex, vector<int> &visited, int &found, vector<int> &recStack){
  visited[vertex] = 1;
  recStack[vertex] = 1;
  for(auto neighbour: adj[vertex]){
    if(recStack[neighbour]==1) found=1;
    if(visited[neighbour] == 0 && found == 0){
      explore(adj, neighbour, visited, found, recStack);
    }
  }
  recStack[vertex] = 0;
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visited(adj.size(), 0);
  vector<int> recStack(adj.size(), 0);
  int found = 0;
  for(int i=0; i<adj.size(); i++){
    if(visited[i] == 0 && found == 0)
    explore(adj, i, visited, found, recStack);
  }
  return found;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
