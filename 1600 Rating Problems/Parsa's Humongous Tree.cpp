#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void dfs(int node, int parent, vector<vector<int>>& graph, vector<array<int, 2>>& nodeValues, vector<vector<ll>>& dp) {
  dp[node][0] = dp[node][1] = 0;

  for (int child : graph[node]) {
    if (child == parent) continue;

    dfs(child, node, graph, nodeValues, dp);
    dp[node][0] += max(abs(nodeValues[node][0] - nodeValues[child][0]) + dp[child][0], abs(nodeValues[node][0] - nodeValues[child][1]) + dp[child][1]);
    dp[node][1] += max(abs(nodeValues[node][1] - nodeValues[child][0]) + dp[child][0], abs(nodeValues[node][1] - nodeValues[child][1]) + dp[child][1]);
  }
}

ll solve() {
  int n; cin >> n;
  vector<array<int, 2>> nodeValues(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> nodeValues[i][0] >> nodeValues[i][1];
  }

  vector<vector<int>> graph(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  vector<vector<ll>> dp(n + 1, vector<ll>(2, -1));
  dfs(1, -1, graph, nodeValues, dp);

  return max(dp[1][0], dp[1][1]);

}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1528/A
