#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int solve() {
  ll a, b; cin >> a >> b;

  ll ans = 0;
  if (a > b) {
    while (a > b) {
      if ((a % 8 == 0) && (a / 8 >= b)) {
        a /= 8;
      } else if ((a % 4 == 0) && (a / 4 >= b)) {
        a /= 4;
      } else if ((a % 2 == 0) && (a / 2 >= b)) {
        a /= 2;
      } else {
        return -1;
      }
      ans++;
    }
  } else if (a < b) {
    while (a < b) {
      if ((a * 8 <= b)) {
        a *= 8;
      } else if ((a * 4 <= b)) {
        a *= 4;
      } else if ((a * 2 <= b)) {
        a *= 2;
      } else {
        return -1;
      }
      ans++;
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1362/A