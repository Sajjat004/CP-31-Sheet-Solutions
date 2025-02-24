#include <bits/stdc++.h>
using namespace std;

bool isBeautiful() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (__gcd(a[i], a[j]) < 3) return true;
    }
  }

  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (isBeautiful() ? "Yes" : "No") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1789/A