#include <bits/stdc++.h>
using namespace std;

int minimumCostToMakeCompatible() {
  int n; cin >> n;
  string s; cin >> s;

  int cost = 0;
  int count = 1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == s[i - 1]) {
      count++;
    } else {
      cost = max(cost, count);
      count = 1;
    }
  }

  cost = max(cost, count);

  return cost + 1;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << minimumCostToMakeCompatible() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1837/B