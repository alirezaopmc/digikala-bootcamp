/** Tavalode Yehoee
 * Alireza Jafartash
 *
 * Ref: https://codeforces.com/contest/1167/submission/77616538
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

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
  int n, m;
  cin >> n >> m;

  P.assign(n, -1);

  for(int i=0; i<m; i++) {
    int k;

    cin >> k;

    if (k == 0) continue;

    int f; // first

    cin >> f;
    f--;

    int x;
    for(int j=1; j<k; j++) {
      cin >> x;
      x--;
      merge(f, x);
    }
  }

  for(int i=0; i<n; i++) {
    cout << rnk(i) << " ";
  }

  cout << endl;
}
