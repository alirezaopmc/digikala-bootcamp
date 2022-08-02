/** Ajor Chini
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

const int MAXN = 1e6+1;
const int MOD = 1e9 + 7;

vector<ll> dp;

void init() {
  dp.assign(MAXN, -1);
  dp[0] = dp[1] = dp[2] = 1;
  dp[3] = 2;

  for(int i=4; i<MAXN; i++) {
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3] - dp[i-4];
    dp[i] = (dp[i] % MOD + MOD) % MOD;
  }
}

int main() {
  init();

  int q;
  cin >> q;

  while(q--) {
    int x;
    cin >> x;
    cout << dp[x] << endl;
  }
}
