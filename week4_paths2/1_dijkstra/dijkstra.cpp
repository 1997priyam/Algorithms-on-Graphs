#include <iostream>
#include <vector>
#include <queue>

using std::vector;
using std::queue;
using std::pair;
using std::priority_queue;
using std::greater;
using std::make_pair;

int distance(vector<vector<int> > &adj, vector<vector<int> > &cost, int s, int t) {
  //write your code her
  vector<int> dist(adj.size(), INT32_MAX);  // vector to store the minimum values from source to each node
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  dist[s] = 0;                    // Dist from source to source is 0
  pq.push(make_pair(dist[s], s)); // Pushing this node into the queue
  int weight_index;               // This is to keep track of the index of weights which is stored in the cost vector.

  while(pq.empty() != true){      // Taking out the vertex from the queue 
    int current = pq.top().second;  // Fetching the vertex number
    pq.pop();                     // Removing the vertex from queue

    weight_index = 0;             
    for(int neighbour: adj[current]){ // Iterating over the neighbours of the popped vertex
      if(dist[neighbour] > dist[current] + cost[current][weight_index]){  // if a short path is available
        dist[neighbour] = dist[current] + cost[current][weight_index]; // Update the short path
        pq.push(make_pair(dist[neighbour], neighbour)); //Push that vertex in the P queue
      }
      weight_index++;   
    }

  }

  if(dist[t] == INT32_MAX) return -1; // If the node is not reachable return -1
  return dist[t]; 
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  vector<vector<int> > cost(n, vector<int>());
  for (int i = 0; i < m; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    adj[x - 1].push_back(y - 1);
    cost[x - 1].push_back(w);
  }
  int s, t;
  std::cin >> s >> t;
  s--, t--;
  std::cout << distance(adj, cost, s, t);
}
