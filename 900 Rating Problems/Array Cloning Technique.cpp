#include <bits/stdc++.h>
using namespace std;

int arrayColor() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  map<int, int> cnt;
  int maxFreq = 0;
  for (int i = 0; i < n; i++) {
    cnt[a[i]]++;
    maxFreq = max(maxFreq, cnt[a[i]]);
  }

  int operations = 0;
  int length = maxFreq;
  while (length < n) {
    operations++;
    int mn = min(length, n - length);
    operations += mn;
    length *= 2;
  }

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << arrayColor() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1665/B
