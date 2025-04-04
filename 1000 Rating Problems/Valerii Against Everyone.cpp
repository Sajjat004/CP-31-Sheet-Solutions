#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int n; cin >> n;
  bool possible = false;
  map<int, int> count;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    count[x]++;

    if (count[x] >= 2) {
      possible = true;
    }
  }

  return possible;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1438/B