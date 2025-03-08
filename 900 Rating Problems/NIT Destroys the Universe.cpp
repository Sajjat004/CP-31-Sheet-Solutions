#include <bits/stdc++.h>
using namespace std;

int movesToDestroyUnivers() {
  int n; cin >> n;
  vector<int> a;
  a.push_back(0);

  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a.push_back(x);
  }
  a.push_back(0);

  int ans = 0;
  int lastZero = 0;
  for (int i = 1; i <= n + 1; i++) {
    if (a[i] == 0) {
      if (i - lastZero > 1) ans++;
      lastZero = i;
    }
  }

  return min(ans, 2);
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << movesToDestroyUnivers() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1696/B