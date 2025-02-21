#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  sort(a.begin(), a.end());

  if (a[0] == a[n - 1]) {
    cout << -1 << '\n';
    return;
  }

  vector<int> b, c;
  for (int i = 0; i < n; ++i) {
    if (a[i] == a[n - 1]) c.push_back(a[i]);
    else b.push_back(a[i]);
  }

  cout << b.size() << ' ' << c.size() << '\n';
  for (int x : b) cout << x << ' ';
  cout << '\n';
  for (int x : c) cout << x << ' ';
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    solve();
  }
    
  return 0;
}


// Problem Link: https://codeforces.com/problemset/problem/1859/A
