#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = s.size();

  auto isPossible = [&] (int k) {
    string t = s;
    int cnt = 0;
    for (int i = 0; (i + k) < n; ++i) {
      if (t[i] == t[i + k]) {
        ++cnt;
      } else if (t[i] == '?' or t[i + k] == '?') {
        ++cnt;
      }  else {
        if (cnt >= k) return true;
        cnt = 0;
      }
    }

    return cnt >= k;
  };

  for (int k = n / 2; k >= 1; --k) {
    if (isPossible(k)) {
      cout << 2 * k << '\n';
      return;
    }
  }
  cout << 0 << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1948/D
