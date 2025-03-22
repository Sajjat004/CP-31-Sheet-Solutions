#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sumOfRange(ll l, ll r) {
  return (r * (r + 1) - l * (l - 1)) / 2;
}

ll solve() {
  int n, k, q; cin >> n >> k >> q;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int cnt = 0;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] <= q) {
      cnt++;
    } else {
      if (cnt >= k) {
        ll sum = sumOfRange(k, cnt);
        ll subAns = 1LL * cnt * (cnt - k + 1) - sum + (cnt - k + 1);
        ans += subAns;
      }

      cnt = 0;
    }
  }

  if (cnt >= k) {
    ll sum = sumOfRange(k, cnt);
    ll subAns = 1LL * cnt * (cnt - k + 1) - sum + (cnt - k + 1);
    ans += subAns;
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

// Problem Link: https://codeforces.com/problemset/problem/1840/C