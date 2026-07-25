#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN = 2e9;

signed main() {
  int N, P, L;
  cin >> N >> P >> L;

  int l = 0, r = MAXN, ans;
  while (l <= r) {
    int mid = (l + r) / 2;
    int pa = mid / P;
    int le = mid / L;
    if (pa * le >= N) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }
  cout << ans;
}
