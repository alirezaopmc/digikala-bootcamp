/*
 * BFS (Interative Impl) on Undirected Graphs
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;

void init() {
  adj.assign(n, vector<int>());
  mrk.assign(n, false);
  par.assign(n, -1);
  h.assign(n, -1);
}

void init() {
  adj.assign(n, vector<int>());
  mrk.assign(n, false);
  par.assign(n, -1);
  h.assign(n, -1);
}

void bfs(int v) {
  queue<int> q;

  q.push(v);
  mrk[v] = true;

  while(! q.empty()) {
    int u = q.front();
    q.pop();

    for(int w : adj[u]) {
      if (! mrk[w]) {
        mrk[w] = true;
        par[w] = u;
        h[w] = h[u] + 1;
        q.push(w);
      }
    }
  }
}

int main() {
  int n; // Number of nodes
  int m; // Number of edges

  int s; // Source node
  
  cin >> n;
  cin >> m;
  cin >> s;
  s--; // 0-based index

  init();

  for(int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--; // 0-based index
    
    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  bfs(s);

  // You can use h here
}
