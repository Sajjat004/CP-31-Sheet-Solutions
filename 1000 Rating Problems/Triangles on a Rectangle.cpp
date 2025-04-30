#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll calculateArea(int height) {
  int k; cin >> k;
  int fistPoint = -1, lastPoint = -1;
  for (int i = 0; i < k; ++i) {
    int x; cin >> x;
    if (i == 0) {
      fistPoint = x;
    } else {
      lastPoint = x;
    }
  }

  ll area = 1LL * (lastPoint - fistPoint) * height;

  return area;
}

ll solve() {
  int w, h; cin >> w >> h;

  ll area1 = calculateArea(h);
  ll area2 = calculateArea(h);
  ll area3 = calculateArea(w);
  ll area4 = calculateArea(w);

  return max({area1, area2, area3, area4});
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1620/B