#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e5 + 5;
int n;
string s[2];
int m[2][N];
int a[2][N];
int dp[2][N];

void changeMin(int &x, int y) { x = min(x, y); }

signed main() {
  cin >> n >> s[0] >> s[1];
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      cin >> m[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < n; j++) {
      if (s[i][j] == '.') {
        a[i][j] = 0;
      } else if (s[i][j] == 'A') {
        a[i][j] = 1;
      } else if (s[i][j] == 'B') {
        a[i][j] = 2;
      }
    }
  }

  int t = n;
  bool ayam = 0, bebek = 0;
  while (t > 0) {
    bool nextAyam = ayam || (s[0][t - 1] == 'A') || (s[1][t - 1] == 'A');
    bool nextbebek = bebek || (s[0][t - 1] == 'B') || (s[1][t - 1] == 'B');
    if (nextAyam && nextbebek) {
      break;
    } else {
      t--;
      ayam = nextAyam;
      bebek = nextbebek;
    }
  }
  int ans = 0;
  int atas = 0, bawah = 0;
  for (int i = 0; i <= t - 1; i++) {
    atas += m[0][i];
    bawah += m[1][i];

    if (a[0][i] == 1) {
      ans += atas;
    }
    if (a[0][i] == 2) {
      cout << -1 << "\n";
      return 0;
    }
    if (a[1][i] == 2) {
      ans += bawah;
    }
    if (a[1][i] == 1) {
      cout << -1 << endl;
      return 0;
    }
  }

  if (ayam) {
    dp[0][t] = m[0][t] + atas;
    dp[1][t] = m[1][t] + dp[0][t];
  }
  if (bebek) {
    dp[1][t] = m[1][t] + bawah;
    dp[0][t] = m[0][t] + dp[1][t];
  }

  for (int i = t + 1; i < n; i++) {
    dp[0][i] = dp[0][i - 1] + m[0][i];
    dp[1][i] = dp[1][i - 1] + m[1][i];

    changeMin(dp[0][i], dp[1][i] + m[0][i]);
    changeMin(dp[1][i], dp[0][i] + m[1][i]);
  }

  for (int i = t; i < n; i++) {
    if (a[0][i]) {
      ans += dp[0][i];
    }
    if (a[1][i]) {
      ans += dp[1][i];
    }
  }

  cout << ans;
}
