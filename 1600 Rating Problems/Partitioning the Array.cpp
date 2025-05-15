#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 0;

  auto isIdentical = [&] (int k) -> bool {
    int gcd = 0;
    for (int i = k; i < n; ++i) {
      gcd = __gcd(gcd, abs(a[i] - a[i - k]));
    }

    return gcd != 1;
  };

  for (int k = 1; k * k <= n; ++k) {
    if (n % k == 0) {
      if (isIdentical(k)) ans++;
      if (k != (n / k) and isIdentical(n / k)) ans++;
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: 