#include <bits/stdc++.h>
using namespace std;

int minOperationToMakeIncreasing() {
  int n; cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  int operations = 0;
  for (int i = n - 2; i >= 0; --i) {
    while (a[i] >= a[i + 1] and a[i] > 0) {
      a[i] /= 2;
      operations++;
    }

    if (a[i] >= a[i + 1]) return -1;
  }

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << minOperationToMakeIncreasing() << '\n';
  }

  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1675/B