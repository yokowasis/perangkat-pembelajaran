#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000000;

int dp1[101][100'001]{};

int go(vector<vector<int>> &adj, vector<int> &a, int u, int c) {
  if (c == 0)
    return 1;
  if (dp1[u][c] != -1)
    return dp1[u][c];
  int ans = 0;
  for (int v : adj[u]) {
    ans = (ans + go(adj, a, v, c)) % MOD;
  }
  if (c == a[u]) {
    ans = (ans + 1) % MOD;
  } else if (c > a[u]) {
    for (int v : adj[u]) {
      ans = (ans + go(adj, a, v, c - a[u])) % MOD;
    }
  }
  return dp1[u][c] = ans;
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  auto dfs = [&](auto &&dfs, int u, int p) -> void {
    if (u > 0) {
      adj[u].erase(find(adj[u].begin(), adj[u].end(), p));
    }
    for (int v : adj[u]) {
      dfs(dfs, v, u);
    }
  };
  dfs(dfs, 0, 0);

  memset(dp1, -1, sizeof(dp1));

  vector<int> ans(m + 1);

  for (int i = 1; i <= m; i++)
    cout << (ans[i] = (ans[i - 1] + go(adj, a, 0, i)) % MOD) << "\n";

  return 0;
}
