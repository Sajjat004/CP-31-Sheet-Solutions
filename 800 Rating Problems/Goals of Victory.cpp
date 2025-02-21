#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    int sum = 0;

    for (int i = 1; i < n; ++i) {
      int x; cin >> x;
      sum += x;
    }

   // The sum of efficiency of all the teams must be 0.
    cout << (-1 * sum) << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1877/A