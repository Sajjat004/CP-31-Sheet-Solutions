#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void oddQueries() {
  int n, q; cin >> n >> q;
  vector<int> a(n + 1);
  vector<ll> prefixSum(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    prefixSum[i] = prefixSum[i - 1] + a[i];
  }

  while (q--) {
    int l, r, k; cin >> l >> r >> k;
    ll sum = prefixSum[n] - (prefixSum[r] - prefixSum[l - 1]);
    sum += k * (r - l + 1);
    cout << (sum & 1 ? "YES" : "NO") << '\n';
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    oddQueries();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1807/D