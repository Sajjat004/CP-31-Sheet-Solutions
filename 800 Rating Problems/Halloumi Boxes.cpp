#include <bits/stdc++.h>
using namespace std;

bool makeNonDecreasing(int n, int k, vector<int> &a) {
  // if k is greater than 1, then we can always make the array non-decreasing
  if (k > 1) return true;

  vector<int> b = a;
  sort(b.begin(), b.end());

  for (int i = 0; i < n; ++i) {
    if (a[i] != b[i]) return false;
  }

  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << (makeNonDecreasing(n, k, a) ? "YES" : "NO") << endl;
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1903/A