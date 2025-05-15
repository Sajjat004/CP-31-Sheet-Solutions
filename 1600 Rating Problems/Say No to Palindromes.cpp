#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n, m; cin >> n >> m;
  string s; cin >> s;
  s = "?" + s;

  vector<string> patterns = {"abc", "acb", "bac", "bca", "cab", "cba"};
  vector<vector<int>> prefixSums(n + 1, vector<int>(6, 0));

  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < 6; ++j) {
      prefixSums[i][j] = prefixSums[i - 1][j] + (s[i] != patterns[j][i % 3]);
    }
  }

  while (m--) {
    int l, r; cin >> l >> r;
    int ans = INT_MAX;

    for (int j = 0; j < 6; ++j) {
      int count = prefixSums[r][j] - prefixSums[l - 1][j];
      ans = min(ans, count);
    }

    cout << ans << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1555/D
