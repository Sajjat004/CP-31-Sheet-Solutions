#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;
  vector<vector<int>> a(k, vector<int>(n));
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  vector<vector<int>> adjList(n + 1);
  vector<int> indegree(n + 1, 0);
  for (auto &v : a) {
    for (int i = 1; i + 1 < n; ++i) {
      adjList[v[i]].push_back(v[i + 1]);
      indegree[v[i + 1]]++;
    }
  }

  queue<int> q;
  for (int i = 1; i <= n; ++i) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  int topoCount = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    topoCount++;
    for (int v : adjList[u]) {
      indegree[v]--;
      if (indegree[v] == 0) {
        q.push(v);
      }
    }
  }

  cout << (topoCount == n ? "YES" : "NO") << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1931/F
