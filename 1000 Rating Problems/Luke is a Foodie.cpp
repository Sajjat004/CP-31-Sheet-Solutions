#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  int maxAffinity = a[0] + x;
  int minAffinity = max(0, a[0] - x);
  int changesOfAffinity = 0;

  for (int i = 1; i < n; ++i) {
    if (a[i] > maxAffinity or a[i] < minAffinity) {
      changesOfAffinity++;
      maxAffinity = a[i] + x;
      minAffinity = max(0, a[i] - x);
    }
  }

  return changesOfAffinity;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}