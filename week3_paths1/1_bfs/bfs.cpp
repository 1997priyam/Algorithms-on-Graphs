#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;

void bfs(vector<vector<int>> adj, int source, vector<int> &dist){
  dist[source] = 0;
  queue<int> q;
  q.push(source);
  while(q.empty() != true){   // Looping on the queue till its not empty
    int vertex = q.front();
    q.pop();
    for(int neighbour: adj[vertex]){    // Iterating over each neighbour of the vertex popped from the queue
      if(dist[neighbour] == -1){        // If the vertex is unvisited
        q.push(neighbour);              // Push it in the queue
        dist[neighbour] = dist[vertex] + 1; // Update its distance as the distance of its parent + 1
      }
    }
  }
}

int distance(vector<vector<int> > &adj, int s, int t) {
  //write your code here         // Implement the BFS traversal and calculate the shortest dist b/w 2 given nodes
  vector<int> dist(adj.size(), -1);
  bfs(adj, s, dist);
  return dist[t];
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, s, t);
}
