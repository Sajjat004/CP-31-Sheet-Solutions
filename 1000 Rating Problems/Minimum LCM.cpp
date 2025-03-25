#include <bits/stdc++.h>
using namespace std;

pair<int, int> minimumLCM() {
  int n; cin >> n;
  
  int a = 1, b = n - 1;

  for (int g = 2; g * g <= n; ++g) {
    if (n % g == 0) {
      a = n / g;
      b = n - a;
      break;
    }
  }

  return {a, b};
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    pair<int, int> ans = minimumLCM();
    cout << ans.first << " " << ans.second << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1765/M