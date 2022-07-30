/*
 * DFS Pishgoo
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int n, m, s, t;

vector<vector<int>> adj; // Adjacancy List
vector<bool> mrk; // Mark
vector<int> par; // Parent
vector<int> h; // Distance

void init() {
  adj.assign(n, vector<int>());
  mrk.assign(n, false);
  par.assign(n, -1);
  h.assign(n, -1);
}

void bfs() {
  queue<int> q;
  q.push(s);
  mrk[s] = true;
  h[s] = 0;

  while(! q.empty()) {
    int u = q.front();
    q.pop();

    for(int w : adj[u]) {
      if (! mrk[w]) {
        par[w] = u;
        mrk[w] = true;
        h[w] = h[u] + 1;
        q.push(w);
      }
    }
  }
}

int main() {
//  ios_base::sync_with_stdio(false);
//  cin.tie(NULL);

  cin >> n;
  cin >> m;
  cin >> s;
  cin >> t;

  s--; t--;

  init();

  for(int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;

    adj[x].push_back(y);
    adj[y].push_back(x);
  }

  bfs();

//  for(int i=0; i<n; i++) {
//    cout << par[i] << " ";
//  }
  if (h[t] == -1) {
    cout << -1 << endl;
    return 0;
  }

  stack<int> st;

  int cur = t;
  while(cur != -1) {
    st.push(cur);
    cur = par[cur];
  }

  cout << h[t] << endl;
  
  while(! st.empty()) {
    cout << (st.top()+1) << " ";
    st.pop();
  }

  cout << endl;
}
