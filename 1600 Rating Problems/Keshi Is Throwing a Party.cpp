#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n; cin >> n;
  vector<array<int, 2>> happyCondition(n);
  for (int i = 0; i < n; i++) {
    cin >> happyCondition[i][0] >> happyCondition[i][1];
  }

  auto isHappy = [&] (int p) {
    int taken = 0;
    for (int i = 0; i < n; ++i) {
      if (taken <= happyCondition[i][1]) {
        int need = p - taken - 1;
        if (need <= happyCondition[i][0]) {
          taken++;
        }
      }

      if (taken == p) break;
    }

    return taken == p;
  };

  int left = 1, right = n;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (isHappy(mid)) {
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  return right;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1610/C
