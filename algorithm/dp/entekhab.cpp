/** Entekhab
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 2001;
const int M = 1e9 + 7;

vector<vector<ll>> dp;

void init() {
  dp.assign(N, vector<ll>(N));

  for(int k=0; k<N; k++) {
    dp[k][0] = 1;
    dp[k][k] = 1;
  }

  for(int i=2; i<N; i++) {
    for(int j=1; j<=i; j++) {
      dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
      if (dp[i][j] >= M) dp[i][j] %= M;
    }
  }
}

int main() {
  init();

  int q;
  cin >> q;

  int n, k;
  for(int i=0; i<q; i++) {
    cin >> n >> k;
    cout << dp[n][k] << endl;
  }
}
