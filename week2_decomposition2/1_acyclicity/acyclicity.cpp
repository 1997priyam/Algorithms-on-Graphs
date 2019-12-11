#include <iostream>
#include <vector>

using std::vector;
using std::pair;

void explore(vector<vector<int> > adj, int vertex, vector<int> &visited, int &found){
  visited[vertex] = 1;
  for(auto neighbour: adj[vertex]){
    if(visited[neighbour] == 0 && found == 0)
    explore(adj, neighbour, visited, found);
    else found = 1;
  }  
}

int acyclic(vector<vector<int> > &adj) {
  //write your code here
  vector<int> visited(adj.size(), 0);
  int found = 0;
  for(int i=0; i<adj.size(); i++){
    if(visited[i] == 0 && found == 0)
    explore(adj, i, visited, found);
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
