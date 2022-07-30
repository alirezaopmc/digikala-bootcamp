/** Masir Manhathani Ba Maximum Vazn
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const bool DEBUG = false;
#define _(x) if(DEBUG) { x }

typedef long long ll;

typedef struct IJ {
  int i;
  int j;
} IJ;

int n, m;
vector<vector<ll>> A;
vector<vector<int>> P;

IJ getIJ(int k) {
  int i = k / m;
  int j = k % m;

  return {i, j};
}

int getK(int i, int j) {
  int k = m * i + j;

  return k;
}

bool isUp(int i, int j) {
  return i+1 == getIJ(P[i][j]).i;
}

void solve() {
  P[n-1][0] = -1;

  for(int i=n-2; i>=0; i--) {
    A[i][0] += A[i+1][0];
    P[i][0] = getK(i+1, 0);
  }

  for(int j=1; j<m; j++) {
    A[n-1][j] += A[n-1][j-1];
    P[n-1][j] = getK(n-1, j-1);
  }

  for(int i=n-2; i>=0; i--) {
    for(int j=1; j<m; j++) {
      if (A[i+1][j] > A[i][j-1]) {
        A[i][j] += A[i+1][j];
        P[i][j] = getK(i+1, j);
      } else {
        A[i][j] += A[i][j-1];
        P[i][j] = getK(i, j-1);
      }
    }
  }

  _(
    for(int i=0; i<n; i++) {
      for(int j=0; j<m; j++) {
        cout << P[i][j] << " ";
      }
      cout << endl;
    }
  )


  cout << A[0][m-1] << endl;

  stack<char> st;

  int x = getK(0, m-1);
  int i, j;

  while(true) {
    i = getIJ(x).i;
    j = getIJ(x).j;

    if (i == n-1 && j == 0) break;

    st.push(isUp(i, j) ? 'U' : 'R');
    
    x = P[i][j];
  }

  while(! st.empty()) {
    cout << st.top();
    st.pop();
  }

  cout << endl;
}

int main() {
  cin >> n >> m;

  A.assign(n, vector<ll>(m));
  P.assign(n, vector<int>(m));

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> A[i][j];
    }
  }

  solve();
}
