#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, d; cin >> n >> d;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  int ans = 0;
  int index = n - 1;
  int availablePlayers = n;
  while (index >= 0) {
    int playerNeeded = (d + a[index]) / a[index];
    if (playerNeeded <= availablePlayers) {
      availablePlayers -= playerNeeded;
      ans++;
    } else {
      break;
    }
    index--;
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cout << solve() << '\n';
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1725/B