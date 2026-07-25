#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<int> A(N + 1, 0), dp(N + 1, -1e18);
  for (int i = 1; i <= N; i++)
    cin >> A[i];
  sort(A.begin(), A.end());
  dp[0] = 0;
  priority_queue<pair<int, int>> pq;
  for (int i = 1; i <= N; i++) {
    if (i >= M)
      pq.push({dp[i - M], i - M});
    while (!pq.empty() && A[i] - A[pq.top().second + 1] > K)
      pq.pop();
    if (!pq.empty())
      dp[i] = pq.top().first + 1;
  }

  if (dp[N] > 0)
    cout << dp[N];
  else
    cout << -1;
  return 0;
}
