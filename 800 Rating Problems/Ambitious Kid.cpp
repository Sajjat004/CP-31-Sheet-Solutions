#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  // find the absolute value of an element that is closest to 0.
  int operations = INT_MAX;
  for (int x : a) {
    operations = min(operations, abs(x));
  }

  cout << operations << '\n';
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1866/A