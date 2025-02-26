#include <bits/stdc++.h>
using namespace std;

long long bombExplodeTimes() {
  int a, b, n; cin >> a >> b >> n;
  long long times = b;

  for (int i = 1; i <= n; ++i) {
    int x; cin >> x;
    times += min(x, a - 1);
  }

  return times;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << bombExplodeTimes() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1875/A