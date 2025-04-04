#include <bits/stdc++.h>
using namespace std;

int solve() {
  int a, b; cin >> a >> b;

  int operations = 0;
  if (b == 1) {
    operations += 1;
    b++;
  }

  while (a > 0) {
    a /= b;
    operations++;
  }

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}