#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];
  sort(b.rbegin(), b.rend());

  vector<int> finalOrder(n + m);
  merge(a.begin(), a.end(), b.begin(), b.end(), finalOrder.begin(), greater<int>());

  for (int i = 0; i < n + m; i++) {
    cout << finalOrder[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1893/B
