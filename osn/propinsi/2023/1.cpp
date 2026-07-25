#include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

signed main() {
  int m = 0, n = 0;
  int suma = 0, sumb = 0;

  cin >> n;
  cin >> m;

  int A[n], B[m];

  for (int i = 0; i < n; i++) {
    cin >> A[i];
    suma += A[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> B[i];
    sumb += B[i];
  }

  if ((float(suma) / n) > (float(sumb) / m)) {
    cout << 0 << endl;
    return 0;
  }

  sort(B, B + m);

  if ((float(suma) / n) <= (float(sumb) / m)) {
    int jumlah = 0;
    for (int i = m - 1; i >= 0; i--) {
      int max = B[i];
      suma += max;
      sumb -= max;
      jumlah += max;
      n++;
      m--;

      if (B[i - 1] == max) {
        continue;
      }

      if ((float(suma) / n) > (float(sumb) / m)) {
        cout << jumlah << endl;
        return 0;
      }
    }
  }

  cout << -1 << endl;
  return 0;
}
