#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> makeItZero() {
  int n; cin >> n;
  vector<int> a(n);
  for (int &x : a) cin >> x;

  vector<pair<int, int>> operations;
  operations.push_back({1, n});
  if (n & 1) {
    operations.push_back({1, n - 1});
    operations.push_back({n - 1, n});
    operations.push_back({n - 1, n});
  } else {
    operations.push_back({1, n});
  }

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    vector<pair<int, int>> operations = makeItZero();
    cout << operations.size() << '\n';
    for (auto [l, r] : operations) {
      cout << l << ' ' << r << '\n';
    }
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1875/A