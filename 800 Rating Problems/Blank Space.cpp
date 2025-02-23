#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    int maxZeros = 0, cnt = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] == 0) {
        ++cnt;
      } else {
        maxZeros = max(maxZeros, cnt);
        cnt = 0;
      }
    }
    maxZeros = max(maxZeros, cnt);

    cout << maxZeros << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1829/B