#include <bits/stdc++.h>
using namespace std;

int removeToMakeBalanced() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  sort(a.begin(), a.end());
  int removes = INT_MAX;
  int cnt = 1, index = 1;
  while (index < n) {
    if (a[index] - a[index - 1] <= k) {
      cnt++;
    } else {
      removes = min(removes, n - cnt);
      cnt = 1;
    }
    index++;
  }

  removes = min(removes, n - cnt);

  return removes;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << removeToMakeBalanced() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1850/D