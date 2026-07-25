#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int banyak_p = 0;
  int banyak_o = 0;
  int banyak_s = 0;
  int banyak_n = 0;
  for (auto huruf : s) {
    if (huruf == 'P') {
      banyak_p++;
    }
  }
  int ans = -1;
  for (auto huruf : s) {
    if (huruf == 'P') {
      banyak_p--;
      if (banyak_o != 0 && banyak_s != 0 && banyak_n != 0) {
        ans = max(ans, banyak_o + banyak_n + banyak_s + banyak_p + 1);
      }
    }
    if (huruf == 'O') {
      banyak_o++;
    }
    if (huruf == 'S') {
      banyak_s++;
    }
    if (huruf == 'N') {
      banyak_n++;
    }
  }
  cout << ans << endl;
}
