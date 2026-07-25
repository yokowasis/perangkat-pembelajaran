#include <bits/stdc++.h>
#include <iostream>
#define int long long

using namespace std;

signed main() {
  int n, m, k;
  cin >> n >> m >> k;
  int a[n];

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a, a + n);

  int tinggi = m + k;
  int berguna = 0;

  for (int i = 0; i < n; i++) {
    if (tinggi >= a[i]) {
      continue;
    } else {
      berguna++;
      tinggi = a[i] + k;
    }
  }

  cout << berguna << endl;
  return 0;
}
