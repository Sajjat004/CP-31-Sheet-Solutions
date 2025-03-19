#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll sumOfMedians() {
  int n, k; cin >> n >> k;
  vector<int> a((n * k)+ 1, 0);
  for (int i = 1; i <= n * k; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());

  ll sumOfMedians = 0;
  int lastIndex = n * k;
  int medianIndex = n / 2;
  for (int i = 0; i < k; i++) {
    sumOfMedians += a[lastIndex - medianIndex];
    lastIndex -= medianIndex + 1;
  }

  return sumOfMedians;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << sumOfMedians() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1440/B