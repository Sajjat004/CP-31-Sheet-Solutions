#include <bits/stdc++.h>
using namespace std;

int maxValue() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  if (n == 1) return 0;

  int ans = INT_MIN;
  for (int i = 0; i < n - 1; ++i) {
    ans = max(ans, a[i] - a[i + 1]);
  }

  int maxValue = a[1];
  for (int i = 2; i < n; ++i) {

    maxValue = max(maxValue, a[i]);
  }
  ans = max(ans, maxValue - a[0]);

  int minValue = a[n - 2];
  for (int i = n - 3; i >= 0; --i) {
    minValue = min(minValue, a[i]);
  }
  ans = max(ans, a[n - 1] - minValue);

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << maxValue() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1726/A