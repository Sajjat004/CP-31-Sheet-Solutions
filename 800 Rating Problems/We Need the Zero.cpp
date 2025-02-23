#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n; cin >> n;
  int XOR = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    XOR ^= x;
  }

  if (XOR == 0) return 0;
  if (n % 2 == 0) return -1;

  return XOR;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1805/A