#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k, x; cin >> n >> k >> x;

  if (x != 1) {
    cout << "YES" << '\n';
    cout << n << '\n';
    for (int i = 0; i < n; ++i) {
      cout << 1 << ' ';
    }
    cout << '\n';

    return;
  }

  if (n % 2 == 0 and k >= 2) {
    cout << "YES" << '\n';
    cout << n / 2 << '\n';
    for (int i = 1; i <= n / 2; ++i) {
      cout << 2 << ' ';
    }
    cout << '\n';

    return;
  }

  if (n % 2 == 1 and k >= 3) {
    n -= 3;
    cout << "YES" << '\n';
    cout << n / 2 + 1 << '\n';
    for (int i = 1; i <= n / 2; ++i) {
      cout << 2 << ' ';
    }
    cout << 3 << '\n';

    return;
  }

  cout << "NO" << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1845/A