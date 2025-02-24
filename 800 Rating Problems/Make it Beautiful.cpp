#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.begin(), a.end());
  int left = 0, right = n - 1;
  int sum = 0;
  vector<int> finalOrder;

  while (left <= right) {
    if (sum != a[right]) {
      finalOrder.push_back(a[right]);
      sum += a[right];
      right--;
    } else if (sum != a[left]) {
      finalOrder.push_back(a[left]);
      sum += a[left];
      left++;
    } else {
      cout << "NO" << '\n';
      return;
    }
  }

  cout << "YES" << '\n';
  for (int i = 0; i < n; i++) {
    cout << finalOrder[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1783/A