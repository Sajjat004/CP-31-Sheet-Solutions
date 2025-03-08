#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    for (int& x : a) {
      if (x == 1) x++;
    }

    for (int i = 0; i < n - 1; ++i) {
      if (a[i + 1] % a[i] == 0) a[i + 1]++;
    }

    for (int x : a) cout << x << ' ';
    cout << '\n';
  }

  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1794/B