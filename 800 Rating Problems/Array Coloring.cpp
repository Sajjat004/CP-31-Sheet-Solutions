#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int x; cin >> x;
      sum += x;
    }

    // If the sum of all elements is odd, then we can't divide them into two parts with equal parity.
    cout << (sum & 1 ? "NO" : "YES") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1857/A