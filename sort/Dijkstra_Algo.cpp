#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back
#define mp make_pair

typedef pair<int, int> iPair;

class Graph {
  int V;
  list<iPair> *adj;

public:
  Graph(int V);
  void addEdge(int u, int v, int w);
  void shortestPath(int s);
};

Graph::Graph(int V) {
  this->V = V;
  adj = new list<iPair> [V];
}

void Graph::addEdge(int u, int v, int w) {
  adj[u].pb(mp(v, w));
  adj[v].pb(mp(u, w));
}

void Graph::shortestPath(int src) {
  priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
  vector<int> dist(V, INF);

  pq.push(mp(0, src));
  dist[src] = 0;
  while (!pq.empty()) {
    int u = pq.top().second;
    pq.pop();
    list<iPair>::iterator it;
    for (it = adj[u].begin(); it != adj[u].end(); it++) {
      int v = it->first;
      int weight = it->second;
      if (dist[v] > dist[u] + weight) {
	dist[v] = dist[u] + weight;
	pq.push(mp(dist[v], v));
      }
    }
  }
  /*
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < V; ++i)
    printf("%d \t\t %d\n", i, dist[i]);
  */
}

int main () {
  int V = 9;
  Graph g(V);

  g.addEdge(0, 1, 4);
  g.addEdge(0, 7, 8);
  g.addEdge(1, 2, 8);
  g.addEdge(1, 7, 11);
  g.addEdge(2, 3, 7);
  g.addEdge(2, 8, 2);
  g.addEdge(2, 5, 4);
  g.addEdge(3, 4, 9);
  g.addEdge(3, 5, 14);
  g.addEdge(4, 5, 10);
  g.addEdge(5, 6, 2);
  g.addEdge(6, 7, 1);
  g.addEdge(6, 8, 6);
  g.addEdge(7, 8, 7);
  
  g.shortestPath(0);
  return 0;
}
