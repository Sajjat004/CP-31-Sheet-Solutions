#include <bits/stdc++.h>
using namespace std;

bool isMostCommon() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  for (int x : a) {
   // Segment of size 1 is always the most common because it contains only one element. 
    if (x == k) return true;
  }

  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (isMostCommon() ? "YES" : "NO") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1878/A