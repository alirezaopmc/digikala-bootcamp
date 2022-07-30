/** Bozorgtarin Zirbaze
 * Alireza Jafartash
 */

#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

vector<ll> dp;

int main() {
  int n;
  cin >> n;

  dp.assign(n, -1);

  ll x;
  for(int i=0; i<n; i++) {
    cin >> x;

    if (i == 0) {
      dp[i] = x;
    } else {
      dp[i] = max(x, dp[i-1]+x);
    }
  }

  ll ans = dp[0];
  for(int i=1; i<n; i++) {
    ans = max(ans, dp[i]);
  }

  cout << ans << endl;
}
