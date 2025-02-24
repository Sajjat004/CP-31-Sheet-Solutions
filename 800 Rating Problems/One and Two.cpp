#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) cin >> a[i];

  vector<int> dp(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    dp[i] = dp[i - 1];
    if (a[i] == 2) dp[i]++;
  }

  for (int i = 1; i < n; ++i) {
    if (dp[i] == (dp[n] - dp[i])) return i;
  }

  return -1;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1788/A