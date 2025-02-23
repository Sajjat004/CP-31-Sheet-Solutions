#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int x, k; cin >> x >> k;

    if (x % k == 0) {
      cout << 2 << '\n';
      cout << 1 << ' ' << x - 1 << '\n';
    } else {
      cout << 1 << '\n';
      cout << x << '\n';
    }
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1837/A