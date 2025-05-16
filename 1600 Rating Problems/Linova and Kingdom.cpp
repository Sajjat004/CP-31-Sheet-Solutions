#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = (int) 2e5 + 5;
vector<vector<int>> graph(N);
vector<int> subtree(N);
vector<int> depth(N, 0);
vector<int> score;

void dfs(int node, int parent) {
  subtree[node] = 1;
  for (int child : graph[node]) {
    if (child != parent) {
      depth[child] = depth[node] + 1;
      dfs(child, node);
      subtree[node] += subtree[child];
    }
  }
  score.push_back(depth[node] - subtree[node] + 1);
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int n, k; cin >> n >> k;
  for (int i = 0; i < n - 1; ++i) {
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  dfs(1, -1);

  sort(score.begin(), score.end(), greater<int>());

  ll ans = 0;
  for (int i = 0; i < k; ++i) {
    ans += score[i];
  }
  cout << ans << '\n';

  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1336/A
