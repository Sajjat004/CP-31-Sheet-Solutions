#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  int bitwiseAND = a[0];
  for (int i = 1; i < n; i++) {
    bitwiseAND &= a[i];
  }

  return bitwiseAND;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1559/A