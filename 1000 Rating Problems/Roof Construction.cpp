#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  int maxPower = (1 << (int)(log2(n) ));

  for (int i = maxPower - 1; i >= 0; --i) {
    cout << i << ' ';
  }
  for (int i = maxPower; i < n; ++i) {
    cout << i << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}