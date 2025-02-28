#include <bits/stdc++.h>
using namespace std;

int permutationSwap() {
  int n; cin >> n;
  int ans = 0;

  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    ans = __gcd(ans, abs(x - i));
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << permutationSwap() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1828/B