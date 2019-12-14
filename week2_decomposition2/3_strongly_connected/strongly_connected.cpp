#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

void explore(int vertex, vector<vector<int> > &adj, vector<int> &visited, stack<int> &st){
  visited[vertex] = 1;
  for(auto neighbour: adj[vertex]){
    if(visited[neighbour] == 0){
      explore(neighbour, adj, visited, st);
    }
  }
  st.push(vertex);
}

void explore_2(int vertex, vector<vector<int> > &adj, vector<int> &visited){
  visited[vertex] = 1;
  for(auto neighbour: adj[vertex]){
    if(visited[neighbour] == 0){
      explore_2(neighbour, adj, visited);
    }
  }
}

vector<vector<int> > get_reverse_graph(vector<vector<int >> &adj){
  vector<vector<int> > reverseGraph(adj.size(), vector<int>());
  for(int i=0; i<adj.size(); i++){
    for(auto x: adj[i]){
      reverseGraph[x].push_back(i);
    }
  }
  return reverseGraph;
}

void reset_visited(vector<int> &visited){
  for(int i=0; i<visited.size(); i++){
    visited[i] = 0;
  }
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  //write your code here
  stack<int> st;
  vector<int> visited(adj.size(), 0);

  for(int i=0; i<adj.size(); i++){    // Creating the post order stack in thi for loop (DFS)
    if(visited[i] == 0){
      explore(i, adj, visited, st);
    }
  }

  vector<vector<int> > adjR = get_reverse_graph(adj);   // Reversing the graph
  reset_visited(visited);                               // Resetting the visited vector to 0

  while(st.empty() != true){                            // Picking node from stack and exploring each one to get SCC
    int vertex = st.top();
    st.pop();

    if(visited[vertex] == 0){
      explore_2(vertex, adjR, visited);
      result++;
    }
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
