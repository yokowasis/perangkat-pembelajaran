#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
#include <iostream>
#include <vector>
#define int long long

using namespace std;

struct NodeData {
  int value;
  NodeData(int nilai = 0) : value(nilai) {}
};

struct EdgeData {
  int to;
  int length;
  EdgeData(int to, int length = 0) : to(to), length(length) {}
};

struct Graph {
  int n;
  vector<NodeData> nodes;       // properties for each node
  vector<vector<EdgeData>> adj; // adjacency list for edges

  Graph(int jumlah) : n(jumlah), nodes(jumlah), adj(jumlah) {}

  void setNodeValue(int index, int nilai) { nodes[index].value = nilai; }

  int getNodeValue(int index) const { return nodes[index].value; }

  void addEdge(int dari, int ke, int panjang = 0, bool duaArah = true) {
    adj[dari].push_back(EdgeData(ke, panjang));
    if (duaArah)
      adj[ke].push_back(EdgeData(dari, panjang));
  }

  int getEdgeLength(int u, int v) const {
    for (auto &edge : adj[u]) {
      if (edge.to == v)
        return edge.length;
    }
    return -1; // not found
  }

  // BFS for unweighted graphs (length ignored)
  vector<int> bfs(int start) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (auto &edge : adj[u]) {
        int v = edge.to;
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }
    return dist;
  }

  // Dijkstra for weighted shortest path
  vector<long long> dijkstra(int start) {
    const long long INF = 1e18;
    vector<long long> dist(n, INF);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                   greater<>>
        pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      if (d > dist[u])
        continue;

      for (auto &edge : adj[u]) {
        int v = edge.to;
        int w = edge.length;

        if (dist[u] + w < dist[v]) {
          dist[v] = dist[u] + w;
          pq.push({dist[v], v});
        }
      }
    }
    return dist;
  }

  vector<vector<int>> getComponents() {
    vector<vector<int>> components;
    vector<bool> visited(n, false);

    function<void(int, vector<int> &)> dfs = [&](int u, vector<int> &comp) {
      visited[u] = true;
      comp.push_back(u);
      for (auto &edge : adj[u]) {
        if (!visited[edge.to]) {
          dfs(edge.to, comp);
        }
      }
    };

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        vector<int> comp;
        dfs(i, comp);
        components.push_back(comp);
      }
    }
    return components;
  }
};

int binaryNearest(const vector<int> &arr, int target) {
  auto it = std::lower_bound(arr.begin(), arr.end(), target);
  if (it == arr.end())
    return arr.back();
  if (it == arr.begin())
    return *it;
  int above = *it;
  int below = *(it - 1);
  if (abs(above - target) < abs(below - target))
    return above;
  if (abs(above - target) > abs(below - target))
    return below;
  return min(above, below); // tie-breaker: smaller value
}

int findMedian(vector<int> arr) {
  sort(arr.begin(), arr.end());
  return arr[arr.size() / 2];
}

template <typename T> double average(const std::vector<T> &data) {
  if (data.empty())
    return 0.0;
  return std::accumulate(data.begin(), data.end(), 0.0) / data.size();
}

signed main() {

  // case 1
  // int jumlah_bebek = 8;
  // int jumlah_jajan = 4;
  // int jumlah_gosip = 6;

  // vector<int> bebek = {0, 10, 20, 30, 40, 50, 60, 70, 80};
  // vector<int> jajan = {30, 40, 50, 60};

  // case 2
  // int jumlah_bebek = 4;
  // int jumlah_jajan = 3;
  // int jumlah_gosip = 0;

  // vector<int> bebek = {0, 1, 2, 13, 14};
  // vector<int> jajan = {20, 10, 20};

  // case real input
  int jumlah_bebek, jumlah_jajan, jumlah_gosip;
  cin >> jumlah_bebek >> jumlah_jajan >> jumlah_gosip;

  vector<int> bebek = {0};
  vector<int> jajan = {};

  for (int i = 0; i < jumlah_bebek; i++) {
    int x;
    cin >> x;
    bebek.push_back(x);
  }

  for (int i = 0; i < jumlah_jajan; i++) {
    int x;
    cin >> x;
    jajan.push_back(x);
  }

  sort(jajan.begin(), jajan.end());

  Graph g(jumlah_bebek + 1);

  for (int i = 1; i < jumlah_bebek + 1; i++) {
    g.setNodeValue(i, bebek[i]);
  }

  for (int i = 0; i < jumlah_gosip; i++) {
    int p, q;
    cin >> p >> q;
    g.addEdge(p, q);
  }

  // case 1
  // g.addEdge(1, 8);
  // g.addEdge(2, 7);
  // g.addEdge(3, 5);
  // g.addEdge(3, 6);
  // g.addEdge(5, 6);
  // g.addEdge(6, 8);

  auto groups = g.getComponents();

  int groupsSize = groups.size();

  // cout << groupsSize;

  int totalTidakPuas = 0;
  for (int i = 1; i < groupsSize; i++) {
    int groupSize = groups[i].size();
    vector<int> groupGosip;

    for (int j = 0; j < groupSize; j++) {
      auto index = groups[i][j];
      auto value = g.getNodeValue(index);
      // cout << index;
      // cout << value;
      groupGosip.push_back(value);
    }

    int median = findMedian(groupGosip);
    auto rata2 = average(groupGosip);
    // cout << rata2;

    // Fixed: Check both closest candies to find minimum dissatisfaction
    // Instead of using only binaryNearest, we check both candidates around the
    // median
    sort(groupGosip.begin(), groupGosip.end());
    long long ketidakpuasanMinimum = 1e18;
    int indexGulali =
        lower_bound(jajan.begin(), jajan.end(), median) - jajan.begin();

    // Check both the candy at indexGulali and the one before it
    int startIdx = (indexGulali > 0) ? indexGulali - 1 : 0;
    for (int k = startIdx; k <= indexGulali && k < (int)jajan.size(); k++) {
      long long ketidakpuasan = 0;
      for (int kesukaan : groupGosip) {
        ketidakpuasan += abs(kesukaan - jajan[k]);
      }
      ketidakpuasanMinimum = min(ketidakpuasan, ketidakpuasanMinimum);
    }
    totalTidakPuas += ketidakpuasanMinimum;
  }

  cout << totalTidakPuas;

  return 0;
}
