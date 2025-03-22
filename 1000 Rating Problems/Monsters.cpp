#include <bits/stdc++.h>
using namespace std;

vector<int> killMonster() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  vector<pair<int, int>> monsterIndex;

  for (int i = 0; i < n; ++i) {
    a[i] %= k;
    if (a[i] == 0) a[i] = k;
    monsterIndex.push_back({a[i], i});
  }

  sort(monsterIndex.begin(), monsterIndex.end(), [&](pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
  });

  vector<int> killOrder;
  for (auto x : monsterIndex) {
    killOrder.push_back(x.second + 1);
  }

  return killOrder;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    vector<int> ans = killMonster();
    for (int x : ans) cout << x << ' ';
    cout << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1849/B