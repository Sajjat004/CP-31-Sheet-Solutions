#include <bits/stdc++.h>
using namespace std;

using ll = long long;

array<ll, 2> solve() {
  int n; cin >> n;
  ll x; cin >> x;

  ll sum = 0;
  ll maxBeauty = 0;
  for (int i = 0; i < n; ++i) {
    ll num; cin >> num;
    sum += num;
    maxBeauty += (num + x - 1) / x;
  }

  ll minBeauty = (sum + x - 1) / x;
  return {minBeauty, maxBeauty};
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    auto [minBeauty, maxBeauty] = solve();
    cout << minBeauty << ' ' << maxBeauty << '\n';
  }
    
  return 0;
}

// Problem Link; https://codeforces.com/problemset/problem/1471/A