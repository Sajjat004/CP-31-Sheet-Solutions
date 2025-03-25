#include <bits/stdc++.h>
using namespace std;

int arrayMergint() {
  int n; cin >> n;
  vector<int> a(n), b(n);
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;

  int countSameValues = 1;
  map<int, int> valueCount;
  int ans = 0;

  for (int i = 1; i < n; i++) {
    if (a[i] == a[i - 1]) {
      countSameValues++;
    } else {
      valueCount[a[i - 1]] = max(valueCount[a[i - 1]], countSameValues);
      ans = max(ans, countSameValues);
      countSameValues = 1;
    }
  }

  valueCount[a[n - 1]] = max(valueCount[a[n - 1]], countSameValues);
  ans = max(ans, countSameValues);

  countSameValues = 1;

  for (int i = 1; i < n; i++) {
    if (b[i] == b[i - 1]) {
      countSameValues++;
    } else {
      ans = max(ans, countSameValues + valueCount[b[i - 1]]);
      countSameValues = 1;
    }
  }

  ans = max(ans, countSameValues + valueCount[b[n - 1]]);

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  for (int i = 1; i <= testCases; i++) {
    cout << arrayMergint() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1831/B