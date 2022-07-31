/** Dominovar
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

vector<ll> dp;

void fillDp(int n) {
  dp.assign(n, -1);

  dp[0] = 0;
  dp[1] = 1;

  for(int i=2; i<n; i++) {
    dp[i] = dp[i-1] + dp[i-2];
    if (dp[i] > MOD) dp[i] -= MOD;
  }
}

int main() {
  int n;
  cin >> n;

  fillDp(n+2);
  cout << dp[n+1] << endl;
}
