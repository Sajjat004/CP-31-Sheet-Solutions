#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve() {
  ll x, y, k; cin >> x >> y >> k;

  ll sticksNeeded = (k * y) + k - 1;
  ll operations = (sticksNeeded + x - 2) / (x - 1);
  operations += k;

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link; https://codeforces.com/problemset/problem/1418/A