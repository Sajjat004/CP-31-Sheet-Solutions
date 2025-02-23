#include <bits/stdc++.h>
using namespace std;

int minimumOperations() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> b = a;
  sort(b.begin(), b.end());

  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) return 0;
  }

  int operations = INT_MAX;
  for (int i = 1; i < n; ++i) {
    int cost = (a[i] - a[i - 1] + 2) / 2;
    operations = min(operations, cost);
  }

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    cout << minimumOperations() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1853/A