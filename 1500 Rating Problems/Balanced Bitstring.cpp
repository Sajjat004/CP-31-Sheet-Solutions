#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;

  int cntZeros = 0, cntOnes = 0;
  for (int i = 0; i < k; ++j) {
    int value = -1;
    for (int j = i; j < n; j += k) {
      if (s[j] != '?') {
        if (value != -1 and value != s[j] - '0') {
          return false;
        }
        value = s[j] - '0';
      }
    }

    if (value != -1) {
      if (value == 0) cntZeros++;
      else cntOnes++;
    }
  }

  return max(cntZeros, cntOnes) <= k / 2;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    if (solve()) cout << "YES\n";
    else cout << "NO\n";
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1404/A
