#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b) {
  cout << "? " << a << " " << b << '\n';
  cout.flush();
  int x; cin >> x;
  return x;
}

void solve() {
  int left = 2, right = 999;
  while (left <= right) {
    int mid1 = left + (right - left) / 3;
    int mid2 = right - (right - left) / 3;
    int value = ask(mid1, mid2);
    if (value == (mid1 * mid2)) {
      left = mid2 + 1;
    } else if (value == ((mid1 + 1) * (mid2 + 1))) {
      right = mid1 - 1;
    } else {
      left = mid1 + 1;
      right = mid2 - 1;
    }
  }

  cout << "! " << left << '\n';
  cout.flush();
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1999/G2
