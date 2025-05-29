#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> subTree;
vector<int> parent;
vector<int> depth;
vector<int> outDegree;

void dfs(int node, int par) {
  parent[node] = par;
  for (int child : graph[node]) {
    if (child != par) {
      outDegree[node]++;
      depth[child] = depth[node] + 1;
      dfs(child, node);
      subTree[node] += subTree[child];
    }
  }
  subTree[node]++;
}

void removedNode(int node, int& minus) {
  if (outDegree[node] > 0) return;
  minus++;

  if (parent[node] == -1) return;
  outDegree[parent[node]]--;
  removedNode(parent[node], minus);
}

int solve() {
  int n; cin >> n;
  graph = vector<vector<int>>(n + 1);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  subTree = vector<int>(n + 1, 0);
  parent = vector<int>(n + 1, -1);
  depth = vector<int>(n + 1, 0);
  outDegree = vector<int>(n + 1, 0);
  dfs(1, -1);

  unordered_map<int, vector<int>> depthMap;
  for (int i = 1; i <= n; i++) {
    depthMap[depth[i]].push_back(i);
  }

  int ans = n - 1;
  int minus = 0;

  for (int i = 0; i < depthMap.size(); ++i) {
    auto nodes = depthMap[i];
    int subAns = 0;
    for (int node : nodes) {
      subAns += (subTree[node] - 1);
    }
    ans = min(ans, subAns + minus);

    for (int node : nodes) {
      if (outDegree[node] == 0) {
        removedNode(node, minus);
      }
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << "\n";
  }

  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/2018/C
