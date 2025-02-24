#include <bits/stdc++.h>
using namespace std;

int minimumOperationToMakeGood() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  int cnt = 1;
  int operations = 0;
  for (int i = 1; i < n; ++i) {
    if (a[i] % 2 == a[i - 1] % 2) {
      cnt++;
    } else {
      operations += (cnt - 1);
      cnt = 1;
    }
  }
  operations += (cnt - 1);

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << minimumOperationToMakeGood() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1777/A