#include <bits/stdc++.h>
using namespace std;

int solve() {
  string a, b;
  cin >> a >> b;

  int n = a.size();
  int m = b.size();

  int minOperations = n + m;

  for (int i = 0; i < m; ++i) {
    for (int j = i; j < m; ++j) {
      string sub = b.substr(i, j - i + 1);
      int pos = a.find(sub);
      if (pos != string::npos) {
        minOperations = min(minOperations, n - (j - i + 1) + m - (j - i + 1));
      }
    }
  }

  return minOperations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1506/C