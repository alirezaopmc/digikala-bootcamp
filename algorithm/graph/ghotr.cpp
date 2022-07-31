/** Ghotr
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<bool> vis;

int u = 0;
int hu = 0;

int dfs(int node, int depth) {
  vis[node] = true;

  if(depth > hu) {
    u = node;
    hu = depth;
  }

  int maxDepth = depth;

  for(int adj_node : adj[node]) {
    if(! vis[adj_node]) {
      int cur = dfs(adj_node, depth+1);

      maxDepth = max(maxDepth, cur);
    }
  }

  return maxDepth;
}

int main() {
  int n;
  cin >> n;

  adj.assign(n, vector<int>());
  vis.assign(n, false);

  int x, y;
  for(int i=0; i<n-1; i++) {
    cin >> x >> y;
    x--; y--;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  dfs(0, 0);

  vis.assign(n, false);

  cout << dfs(u, 0) << endl;
}
