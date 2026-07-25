#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <iterator>
#include <vector>
#define int long long

using namespace std;

int jumlah_pagar(int potong, vector<int> &arr) {
  int sum = 0;
  for (auto r : arr) {
    if (r > potong) {
      sum += r - potong;
    }
  }

  return sum;
}

int find_me(int first, int last, vector<int> &arr, double target) {
  int middle = first + ((last - first) / 2);

  int potong_tengah = jumlah_pagar(middle, arr);

  if (first > last) {
    if (potong_tengah < target) {
      return middle - 1;
    }

    return middle;
  } else if (potong_tengah == target) {
    return middle;
  } else if (target < potong_tengah) {
    return (find_me(middle + 1, last, arr, target));
  } else {
    return (find_me(first, middle - 1, arr, target));
  }
}

signed main() {

  int jumlah_pohon;
  cin >> jumlah_pohon;

  int tinggi_pagar;
  cin >> tinggi_pagar;

  vector<int> pohon;

  for (int i = 0; i < jumlah_pohon; i++) {
    int x;
    cin >> x;
    pohon.push_back(x);
  }

  int min = 0;
  int max = 0;

  for (int i = 0; i < pohon.size(); i++) {
    if (pohon[i] > max) {
      max = pohon[i];
    }
  }

  cout << find_me(0, max, pohon, tinggi_pagar);

  return 0;
}
