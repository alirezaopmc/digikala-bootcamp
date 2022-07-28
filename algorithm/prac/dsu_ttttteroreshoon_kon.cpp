/** Terooreshooon Kon
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<int> A;
vector<int> V;
vector<int> C;
vector<int> R;

int label = 2;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n;
  cin >> n;

  A.assign(n, -1);
  V.assign(n, 0);
  C.assign(n, 0);

  for(int i=0; i<n; i++) {
    cin >> A[i];
    A[i]--;
  }

  for(int i=0; i<n; i++) {
    cin >> C[i];
  }

  for(int i=0; i<n; i++) {
    if(V[i] > 0) continue;

    // Inline DFS
    int node = i;

    // No need to use stack just keep the next node
    int u = node;
                 
    V[u] = 1;

    while(true) {
      u = A[u];

      if (V[u] == 0) {
        V[u] = 1;
      } else if (V[u] == 1) {
        V[u] = label;
      } else if (V[u] == label) {
        label++;
        break;
      } else {
        break;
      }
    }

    while(V[node] == 1) {
      V[node] = -1;
      node = A[node];
    }

  }

  R.assign(label, 1e9);

  for(int i=0; i<n; i++) {
    if (V[i] > 1) {
      R[V[i]] = min(R[V[i]], C[i]);
    }
  }

/*
  for(int i=0; i<n; i++) {
    cout << V[i] << " ";
  }
  cout << endl;
*/
  
  ll ans = 0;
  for(int i=2; i<label; i++) {
    ans += R[i];
  }
  cout << ans << endl;
}
