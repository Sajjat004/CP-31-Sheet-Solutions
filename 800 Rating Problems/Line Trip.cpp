#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (int &i : a) cin >> i;

    // Minimum gas tank size is the maximum distance between two consecutive gas stations
    int gasTankSize = a[0];
    for (int i = 1; i < n; ++i) {
      gasTankSize =  max(gasTankSize, a[i] - a[i - 1]);
    }
    gasTankSize = max(gasTankSize, 2 * (x - a[n - 1]));

    cout << gasTankSize << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1901/A