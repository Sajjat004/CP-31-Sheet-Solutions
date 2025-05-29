#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int breaker, int currentXor, vector<vector<pair<int, int>>>& adjList, set<int>& xorValues) {
  for (auto& [neighbor, weight] : adjList[node]) {
    if (neighbor != parent && neighbor != breaker) {
      int newXor = currentXor ^ weight;
      xorValues.insert(newXor);
      dfs(neighbor, node, breaker, newXor, adjList, xorValues);
    }
  }
}

void solution() {
  int n, a, b; cin >> n >> a >> b;
  vector<vector<pair<int, int>>> adjList(n + 1);
  for (int i = 1; i < n; i++) {
    int u, v, w; cin >> u >> v >> w;
    adjList[u].emplace_back(v, w);
    adjList[v].emplace_back(u, w);
  }

  set<int> xorValuesOfA, xorValuesOfB;
  dfs(a, -1, b, 0, adjList, xorValuesOfA);
  dfs(b, -1, -1, 0, adjList, xorValuesOfB);

  for (int value : xorValuesOfA) {
    if (xorValuesOfB.count(value)) {
      cout << "YES\n";
      return;
    }
  }

  if (xorValuesOfB.count(0)) {
    cout << "YES\n";
    return;
  }

  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  int tests; cin >> tests;
  while (tests--) {
    solution();
  }
    
  return 0;
}

// Problem Link: 
