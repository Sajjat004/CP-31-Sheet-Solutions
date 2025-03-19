#include <bits/stdc++.h>
using namespace std;

void threeIndices() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i < n - 1; i++) {
    if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
      cout << "YES" << '\n';
      cout << i << ' ' << i + 1 << ' ' << i + 2 << '\n';
      return;
    }
  }

  cout << "NO" << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    threeIndices();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1380/A