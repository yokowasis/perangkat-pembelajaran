#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
  LL N;
  cin >> N;

  LL x = N;
  LL nEggType = -1;
  int nMinExp = 1e9;

  for (LL p = 2; p * p <= x; p++) {
    if (x % p != 0)
      continue;

    int nBestExp = 0;
    while (x % p == 0) {
      nBestExp++;
      x /= p;
    }

    if (nBestExp < nMinExp) {
      nMinExp = nBestExp;
      nEggType = p;
    }
  }

  if (x > 1) {
    int nBestExp = 1;

    if (nBestExp < nMinExp) {
      nMinExp = nBestExp;
      nEggType = x;
    }
  }

  cout << nEggType << '\n';

  return 0;
}
