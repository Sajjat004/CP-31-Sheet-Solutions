#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<vector<int>> a(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }

  string s[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    s[i] = "0" + s[i];
  }

  ll diff = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '1') {
        diff += a[i][j];
      } else {
        diff -= a[i][j];
      }
    }
  }

  diff = abs(diff);
  if (diff == 0) {
    cout << "YES" << '\n';
    return;
  }

  vector<vector<ll>> sum(n + 1, vector<ll>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (s[i][j] == '1');
    }
  }

  auto isValid = [&] (int x, int y) {
    if (x < 1 || x > n || y < 1 || y > m) return false;
    return true;
  };

  auto query = [&](int x1, int y1, int x2, int y2) -> ll {
    if (!isValid(x1, y1) || !isValid(x2, y2)) return -1;
    return sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1 - 1][y1 - 1];
  };

  ll gcd = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      ll ones = query(i, j, i + k - 1, j + k - 1);
      if (ones == -1) continue;
      ll zeros = 1LL * k * k - ones;
      gcd = __gcd(gcd, abs(ones - zeros));
    }
  }
  
  if (gcd == 0) {
    cout << "NO" << '\n';
    return;
  }

  cout << (diff % gcd == 0 ? "YES" : "NO") << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test = 1; cin >> test;
  while (test--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1982/D
