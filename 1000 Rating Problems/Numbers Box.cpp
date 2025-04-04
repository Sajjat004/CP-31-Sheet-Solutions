#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, m; cin >> n >> m;
  int negativeNumbers = 0;
  int minNumber = INT_MAX;
  int sum = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int x; cin >> x;
      if (x < 0) {
        negativeNumbers++;
        x *= -1;
      }

      minNumber = min(minNumber, x);
      sum += x;
    }
  }

  if (minNumber == 0) return sum;
  if (negativeNumbers % 2 == 0) return sum;

  return sum - (2 * minNumber);
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1447/B