#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void preCal(vector<int>& cnt) {
  for (int d = 0; d < 10; ++d) {
    for (int i = 0; i < 10; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) {
          if (i + j + k == d) cnt[d]++;
        }
      }
    }
  }
}

ll solve(vector<int>& cnt) {
  int n; cin >> n;
  ll ans = 1;

  while (n) {
    int digit = n % 10;
    ans *= cnt[digit];
    n /= 10;
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  vector<int> cnt(10, 0);
  preCal(cnt);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve(cnt) << '\n';
  }

  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1907/E
