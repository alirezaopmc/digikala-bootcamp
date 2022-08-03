#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector<vector<ll>> dp;
vector<ll> a;

void init() {
  dp.assign(n, vector<ll>(n, 0));

  for(int L=2; L<n; L++) {
    for(int i=1; i<n-L+1; i++) {
      int j = i + L - 1;
      dp[i][j] = 1e18;

      for(int k=i; k<j; k++) {
        ll q = dp[i][k] + dp[k+1][j] + a[i-1] * a[k] * a[j];

        if (q < dp[i][j]) {
          dp[i][j] = q;
        }
      }
    }
  }
}

int main() {
  cin >> n;

  n++;
  a.assign(n, -1);
  for(int i=0; i<n; i++) {
    cin >> a[i];
  }

  if (n == 2) {
    cout << (a[0] * a[1]) << endl;
    return 0;
  }

  init();

  cout << dp[1][n-1];
}
