#include <iostream>

int main() {

  int n, m;

  std::cin >> n >> m;

  if (n > m) {
    int x = m;
    m = n;
    n = x;
  }

  std::cout << ((m + m * m) / 2) + ((m + n) * (n - 1));

  return 0;
}
