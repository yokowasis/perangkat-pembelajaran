#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

int n, k;
string s;
vector<int> dif;

int main() {
  cin >> n >> k;
  cin >> s;
  int tmp = 0;
  int totalB = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'B')
      tmp++, totalB++;
    else {
      if (tmp != i && tmp != 0)
        dif.push_back(tmp);
      tmp = 0;
    }
  }
  sort(dif.begin(), dif.end());
  int ans = 0;
  for (int i = 0; i < (int)dif.size() - k + 1; i++) {
    ans += dif[i];
  }
  cout << totalB - ans << "\n";
  return 0;
}
