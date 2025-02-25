#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll rangSum(ll n) {
  return n * (n + 1) / 2;
}

ll rangSum(ll l, ll r) {
  return rangSum(r) - rangSum(l - 1);
}

bool makeSum() {
  ll n, k, x; cin >> n >> k >> x;

  ll mn = rangSum(k);
  ll mx = rangSum(n - k + 1, n);

  return x >= mn and x <= mx;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (makeSum() ? "YES" : "NO") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1878/C