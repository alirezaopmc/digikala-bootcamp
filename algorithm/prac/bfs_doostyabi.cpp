/** Doost Yabi
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;
vector<bool> v;
vector<int> h;

int w = -1;
int hw = -1;

void bfs(int node) {
  queue<int> q;
  q.push(node);
  vis[node] = true;
  h[node] = 0;

  while(! q.empty()) {
    int u = q.front();
    q.pop();

    if (v[u]) {
      if (w == -1) {
        w = u;
        hw = h[u];
      } else if (h[u] == hw && u < w) {
        w = u;
      }
    }

    for(int adj_node : adj[u]) {
      if (! vis[adj_node]) {
        q.push(adj_node);
        vis[adj_node] = true;
        h[adj_node] = h[u] + 1;
      }
    }
  }
}

int main() {
  int n;
  cin >> n;

  adj.assign(n, vector<int>());
  vis.assign(n, false);
  h.assign(n, -2);
  v.assign(n, false);

  int x, y;
  for(int i=0; i<n-1; i++) {
    cin >> x >> y;
    x--; y--;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  int q;
  cin >> q;

  for(int i=0; i<q; i++) {
    cin >> x;
    x--;

    v[x] = true;
  }

  bfs(0);
  cout << w+1 << endl;
}
