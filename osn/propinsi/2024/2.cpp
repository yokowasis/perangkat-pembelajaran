#include <bits/stdc++.h>
using namespace std;
#define int long long
#define vi vector<int>

const int MOD = 1e9 + 7;
signed main() {
  int b, c, d;
  cin >> b >> c >> d;
  int calon = c - d;
  if (c == d) {
    cout << max(0LL, b - d);
    return 0;
  }
  int cnt = 0;
  for (int i = 1; i * i <= calon; i++) {
    if (calon % i == 0) {
      if (i > d && i <= b)
        cnt++;
      if (calon / i > d && calon / i <= b && calon / i != i)
        cnt++;
    }
  }
  cout << cnt << '\n';
  return 0;
}
