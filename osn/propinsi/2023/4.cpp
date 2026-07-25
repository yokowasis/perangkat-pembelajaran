#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, K, X;
  cin >> N >> K >> X;

  vector<int> A(N), B(N);

  for (int i = 0; i < N; i++)
    cin >> A[i];

  for (int i = 0; i < N; i++)
    cin >> B[i];

  vector<int> pref(N + 1, 0);

  for (int i = 0; i < N; i++) {
    pref[i + 1] = pref[i] + B[i];
  }

  int ans = 0;

  int l = lower_bound(A.begin(), A.end(), X) - A.begin();
  int r = upper_bound(A.begin(), A.end(), X + K) - A.begin();

  ans = max(ans, pref[r] - pref[l]);

  l = lower_bound(A.begin(), A.end(), X - K) - A.begin();
  r = upper_bound(A.begin(), A.end(), X) - A.begin();

  ans = max(ans, pref[r] - pref[l]);

  for (int i = 0; i < N; i++) {

    if (A[i] >= X)
      break;

    int jarakKiri = X - A[i];

    if (jarakKiri > K)
      continue;

    /*
        Perjalanan:

        X -> A[i] -> batasKanan

        biaya:
        (X - A[i]) + (batasKanan - A[i]) <= K

        sehingga:

        batasKanan <= K - X + 2*A[i]
    */

    int batasKanan = K - X + 2 * A[i];

    int j = upper_bound(A.begin(), A.end(), batasKanan) - A.begin();

    if (j > i) {
      ans = max(ans, pref[j] - pref[i]);
    }
  }

  for (int j = 0; j < N; j++) {

    if (A[j] <= X)
      continue;

    int jarakKanan = A[j] - X;

    if (jarakKanan > K)
      break;

    /*
        Perjalanan:

        X -> A[j] -> batasKiri

        biaya:
        (A[j] - X) + (A[j] - batasKiri) <= K

        sehingga:

        batasKiri >= 2*A[j] - X - K
    */

    int batasKiri = 2 * A[j] - X - K;

    int i = lower_bound(A.begin(), A.end(), batasKiri) - A.begin();

    if (i <= j) {
      ans = max(ans, pref[j + 1] - pref[i]);
    }
  }

  cout << ans << '\n';

  return 0;
}
