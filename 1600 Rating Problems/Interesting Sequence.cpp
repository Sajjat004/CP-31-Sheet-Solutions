#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll solve() {
  ll n, x; cin >> n >> x;
  if (n == x) return n;

  bool bothSet1 = false;

  for (int i = 0; i < 63; ++i) {
    bool bitOfX = (x >> i) & 1;
    bool bitOfN = (n >> i) & 1;

    if (bitOfN == 0 and bitOfX == 1) return -1;

    if (bitOfN == 1 and bitOfX == 1) bothSet1 = true;
    if (bothSet1 and bitOfN == 1 and bitOfX == 0) return -1;
  }

  ll ans = 0;
  for (int i = 62; i >= 0; --i) {
    bool bitOfX = (x >> i) & 1;
    bool bitOfN = (n >> i) & 1;

    if (bitOfN == 1 and bitOfX == 1) {
      ans |= (1LL << i);
    } else if (bitOfN == 1 and bitOfX == 0) {
      bool preBitOfN = (n >> (i + 1)) & 1;
      if (preBitOfN) return -1;
      ans |= (1LL << (i + 1));
      break;
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1775/C
