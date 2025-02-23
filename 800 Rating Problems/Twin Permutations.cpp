#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    for (int i = 1; i <= n; ++i) {
      cout << n + 1 - a[i - 1] << ' ';
    }
    cout << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1831/A