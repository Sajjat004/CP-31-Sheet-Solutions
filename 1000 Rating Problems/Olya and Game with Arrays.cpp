#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll maxBeautyOfArray() {
  int n; cin >> n;
  vector<vector<ll>> a(n, vector<ll>());

  for (int i = 0; i < n; ++i) {
    int m; cin >> m;
    for (int j = 0; j < m; ++j) {
      ll x; cin >> x;
      a[i].push_back(x);
    }
    sort(a[i].begin(), a[i].end());
  }

  vector<ll> firstColumn;
  vector<ll> secondColumn;

  for (int i = 0; i < n; ++i) {
    firstColumn.push_back(a[i][0]);
    secondColumn.push_back(a[i][1]);
  }

  sort(firstColumn.begin(), firstColumn.end());
  sort(secondColumn.begin(), secondColumn.end());

  ll beauty = 0;
  for (int i = n - 1; i > 0; --i) {
    beauty += secondColumn[i];
  }
  beauty += firstColumn[0];

  return beauty;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << maxBeautyOfArray() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1859/B