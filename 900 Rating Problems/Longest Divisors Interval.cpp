#include <bits/stdc++.h>
using namespace std;

int longestDivisor() {
  long long n; cin >> n;

  int ans = 0;
  for (int i = 1; i <= 10000; ++i) {
    int cnt = 0;
    int divisor = i;
    while (n % divisor == 0) {
      cnt++;
      divisor++;
    }
    ans = max(ans, cnt);
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << longestDivisor() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1855/B