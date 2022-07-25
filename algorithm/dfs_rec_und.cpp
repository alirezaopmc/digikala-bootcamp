/*
 * DFS (Recursive Impl) on Undirected Graphs
 */

#include <iostream>
#include <vector>

using namespace std;

int n;
int dfs_timer = 0;

vector<vector<int>> adj; // Adjacancy List
vector<bool> mrk; // Mark
vector<int> par; // Parent
vector<int> st; // Starting time
vector<int> fi; // Finishing Time
vector<int> tree; // Subtree Nodes Count
vector<int> h; // Height

void init() {
  adj.assign(n, vector<int>());
  mrk.assign(n, false);
  par.assign(n, -1);
  st.assign(n, 0);
  fi.assign(n, 0);
  tree.assign(n, 0);
  h.assign(n, -1);
}

void dfs(int v) {
  mrk[v] = true;
  st[v] = dfs_timer++;
  tree[v] = 1;

  for(int u : adj[v]) {
    if(! mrk[u]) {
      par[u] = v;
      h[u] = h[v] + 1;

      dfs(u);

      tree[v] += tree[u];
    } else {
      // Backedge
    }
  }

  fi[v] = dfs_timer;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  // Your code here
}
