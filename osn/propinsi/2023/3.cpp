#include <bits/stdc++.h>
using namespace std;

#define int long long

struct DSU {
  vector<int> parent, sz;

  DSU(int n) {
    parent.resize(n);
    sz.assign(n, 1);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] == x)
      return x;

    return parent[x] = find(parent[x]);
  }

  void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b)
      return;

    if (sz[a] < sz[b])
      swap(a, b);

    parent[b] = a;
    sz[a] += sz[b];
  }
};

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M, K;
  cin >> N >> M >> K;

  vector<int> A(N);
  vector<int> B(M);

  for (int i = 0; i < N; i++)
    cin >> A[i];

  for (int i = 0; i < M; i++)
    cin >> B[i];

  DSU dsu(N);

  for (int i = 0; i < K; i++) {
    int u, v;
    cin >> u >> v;

    u--;
    v--;

    dsu.unite(u, v);
  }

  const int INF = 4e18;

  vector<int> minimum(N, INF);

  for (int i = 0; i < N; i++) {
    int root = dsu.find(i);

    minimum[root] = min(minimum[root], A[i]);
  }

  vector<int> component;

  for (int i = 0; i < N; i++) {
    if (dsu.find(i) == i) {
      component.push_back(minimum[i]);
    }
  }

  int jumlahComponent = component.size();

  if (jumlahComponent > M) {
    cout << -1 << '\n';
    return 0;
  }

  sort(B.begin(), B.end());

  sort(component.rbegin(), component.rend());

  int answer = 0;

  for (int i = 0; i < jumlahComponent; i++) {
    answer += component[i] * B[i];
  }

  cout << answer << '\n';

  return 0;
}
