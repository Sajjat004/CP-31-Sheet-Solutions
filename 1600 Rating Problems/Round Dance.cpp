#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<set<int>> graph(n + 1);

  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    graph[x].insert(i);
    graph[i].insert(x);
  };

  vector<int> degree(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    degree[i] = graph[i].size();
  }

  vector<bool> visited(n + 1, false);

  auto dfs = [&] (int source) -> bool { // If cycle exists then return true otherwise false
    stack<int> s;
    s.push(source);
    visited[source] = true;
    set<int> components;


    while (!s.empty()) {
      int node = s.top();
      s.pop();

      components.insert(node);

      for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          s.push(neighbor);
        }
      }
    }
    
    for (int node : components) {
      if (degree[node] != 2) return false;
    }

    return true;
  };

  int cycles = 0, bamboos = 0;
  for (int i = 1; i <= n; ++i) {
    if (!visited[i]) {
      if (dfs(i)) cycles++;
      else bamboos++;
    }
  }

  cout << cycles + min(bamboos, 1) << ' ' << cycles + bamboos << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1833/E
