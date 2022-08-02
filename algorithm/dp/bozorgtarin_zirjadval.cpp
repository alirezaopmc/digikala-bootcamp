/** Bozorg Tarin Zir Jadval
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, m;
vector<vector<ll>> dp;

ll get(int r1, int r2, int j) {
  if (r1 == 0) return dp[r2][j];
  else return dp[r2][j] - dp[r1-1][j];
}

int main() {
  cin >> n >> m;

  dp.assign(n, vector<ll>(m));

  for(int i=0; i<n; i++) {
    for(int j=0; j<m; j++) {
      cin >> dp[i][j];
    }
  }

  for(int j=0; j<m; j++) {
    for(int i=1; i<n; i++) {
      dp[i][j] += dp[i-1][j];
    }
  }

  ll ans = dp[0][0];
  for(int r1=0; r1<n; r1++) {
    for(int r2=r1; r2<n; r2++) {
      ll cur;

      for(int j=0; j<m; j++) {
        ll x = get(r1, r2, j);
//        printf("r1: %d, r2: %d, j: %d, cur: %lld, x: %lld\n", r1, r2, j, x, cur);

        if (j == 0) {
          cur = x;
        } else {
          cur = max(x, cur+x);
        }
        ans = max(ans, cur);
      }
    }
  }
  cout << ans << endl;
}
