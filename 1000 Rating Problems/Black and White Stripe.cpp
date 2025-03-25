#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  vector<int> whileStripes(n + 1, 0);
  for (int i = 0; i < n; i++) {
    whileStripes[i + 1] = whileStripes[i] + (s[i] == 'W');
  }

  int ans = k;
  for (int i = k; i <= n; ++i) {
    ans = min(ans, whileStripes[i] - whileStripes[i - k]);
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1690/D