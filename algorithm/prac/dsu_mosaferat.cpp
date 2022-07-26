/** DFS Mosaferat
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

const int N = 1000;
int x_cnt = 1;
int y_cnt = N + 1;

map<int, int> _tx;
map<int, int> _ty;

vector<int> X;
vector<int> Y;

int tx(int x) {
  if (_tx[x] == 0) _tx[x] = x_cnt++;
  return _tx[x];
}

int ty(int y) {
  if (_ty[y] == 0) _ty[y] = y_cnt++;
  return _ty[y];
}

vector<int> P; // Parent

int find(int u) {
  if (P[u] < 0) return u;

  int root = u;

  while(P[root] >= 0) root = P[root];

  while(P[u] >= 0) {
    int tmp = P[u];
    P[u] = root;
    u = P[u];
  }

  return root;
}

int rnk(int u) {
  return - P[find(u)];
}

void merge(int u, int v) {
  int pu = find(u);
  int pv = find(v);

  if (pu == pv) return;

  if (rnk(u) < rnk(v)) {
    P[pv] += P[pu];
    P[pu] = pv;
  } else {
    P[pu] += P[pv];
    P[pv] = pu;
  }
}


int main() {
  int n;
  cin >> n;

  P.assign(2*N+1, -1);
  X.assign(n, -1);
  Y.assign(n, -1);

  int x, y;
  for(int i=0; i<n; i++) {
    cin >> x >> y;

    x = tx(x);
    y = ty(y);

    X[i] = x;
    Y[i] = y;

    merge(x, y);
  }

  set<int> st;

  for(int i=0; i<n; i++) {
    st.insert(find(X[i]));
  }

  cout << (st.size() - 1) << endl;
}
