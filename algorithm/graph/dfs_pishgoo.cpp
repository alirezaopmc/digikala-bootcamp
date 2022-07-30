/*
 * DFS Pishgoo
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n, m, s, t;

vector<vector<int>> adj; // Adjacancy List
vector<bool> mrk; // Mark

void init() {
  adj.assign(n, vector<int>());
  mrk.assign(n, false);
}

bool dfsRec(int s) {
  mrk[s] = true;

  for(int w : adj[s]) {
    if (! mrk[w]) {
      if (w == t) return true;

      mrk[w] = true;

      if (dfsRec(w)) return true;
    }
  }

  return false;
}

/*
bool dfsIte(int s) {
  stack<int> st;

  st.push(node);

  while(! st.empty()) {
    int u = st.top();
    st.pop();

    for(int w : adj[u]) {
      if (! mrk[w]) {
        if (w == t) return true;
        mrk[w] = true;
        st.push(w);
      }
    }
  }

  return false;
}
*/


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

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

  cout << (dfsRec(s) ? "YES" : "NO") << endl;
}
