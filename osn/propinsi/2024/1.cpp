#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>

#define int long long

using namespace std;

signed main() {

  vector<string> osn_yg_valid = {"OSN", "ONS", "SNO", "SON", "NOS", "NSO"};

  string s = "INFORMATIKA";
  cin >> s;

  int max_osn = -1;

  for (int i = 0; i < osn_yg_valid.size(); i++) {

    string osn = osn_yg_valid[i];

    // cout << osn;

    int idx = 0;

    string s_terpanjang = "";
    for (int j = 0; j < s.size(); j++) {
      char chr = s[j];
      // cout << chr;

      if (chr == osn[idx]) {
        // cout << chr;
        s_terpanjang.push_back(chr);
        idx++;
        if (idx >= 3) {
          idx = 0;
        }
      }
    }

    int panjang_string = s_terpanjang.size();

    // cout << panjang_string;

    if (panjang_string >= 3) {
      max_osn = max(max_osn, panjang_string);
    }
  }

  cout << max_osn;

  return 0;
}
