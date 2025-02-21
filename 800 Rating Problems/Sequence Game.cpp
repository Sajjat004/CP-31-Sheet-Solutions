#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    vector<int> b(n);
    for (int& x : b) cin >> x;

    vector<int> a;
    a.push_back(b[0]);
    for (int i = 1; i < n; ++i) {
      a.push_back(b[i]);
      if (b[i] < b[i - 1]) a.push_back(b[i]);
    }

    cout << a.size() << '\n';
    for (int x : a) cout << x << ' ';
    cout << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1862/B