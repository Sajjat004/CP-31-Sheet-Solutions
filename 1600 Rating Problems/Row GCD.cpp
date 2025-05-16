#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void rowGCD() {
  int n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  ll g = 0;
  for (int i = 1; i < n; i++) {
    g = __gcd(g, abs(a[i] - a[0]));
  }

  for (int i = 0; i < m; i++) {
    cout << __gcd(g, a[0] + b[i]) << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  rowGCD();
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1458/A

// Key Insight: GCD(a, b) = GCD(a, b - a) according to the euclidean algorithm.
