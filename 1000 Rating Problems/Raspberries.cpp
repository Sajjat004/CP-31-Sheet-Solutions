#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, k; cin >> n >> k;
  int ans = k;

  int oddCount = 0;
  int evenCount = 0;
  
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    x %= k;
    if (x == 0) ans = 0;
    ans = min(ans, k - x);

    if (x % 2 == 0) evenCount++;
    else oddCount++;
  }

  if (k == 4) {
    if (evenCount > 1) ans = min(ans, 0);
    if (evenCount > 0 and oddCount > 0) ans = min(ans, 1);
    if (oddCount > 1) ans = min(ans, 2);
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1883/C