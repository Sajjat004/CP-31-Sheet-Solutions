#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n; cin >> n;
  string s; cin >> s;

  vector<vector<int>> prefixSumOfCharacters(n + 1, vector<int>(26, 0));
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      prefixSumOfCharacters[i][j] = prefixSumOfCharacters[i - 1][j];
    }

    prefixSumOfCharacters[i][s[i - 1] - 'a']++;
  }

  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int cnt1 = 0;
    for (int j = 0; j < 26; j++) {
      if (prefixSumOfCharacters[i][j] > 0) {
        cnt1++;
      }
    }

    int cnt2 = 0;
    for (int j = 0; j < 26; j++) {
      if (prefixSumOfCharacters[n][j] - prefixSumOfCharacters[i][j] > 0) {
        cnt2++;
      }
    }

    ans = max(ans, cnt1 + cnt2);
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  for (int i = 1; i <= testCases; i++) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1791/D