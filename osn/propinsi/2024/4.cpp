#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  long long B;
  string Y;
  if (!(cin >> B >> Y))
    return 0;

  int n = Y.length();
  vector<long long> dp(n + 1, 0);

  dp[n] = 1;

  for (int i = n - 1; i >= 0; i--) {
    if (Y[i] == '0') {
      dp[i] = dp[i + 1];
    } else {
      long long val = 0;
      for (int j = i; j < n; j++) {
        val = val * 10 + (Y[j] - '0');

        if (val >= B) {
          break;
        }

        dp[i] = (dp[i] + dp[j + 1]) % MOD;
      }
    }
  }

  cout << dp[0] << "\n";

  return 0;
}
