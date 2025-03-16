#include <bits/stdc++.h>
using namespace std;

long long numberOfNearlyFullSequences() {
  int n; cin >> n;
  long long zero = 0, one = 0;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x == 0) zero++;
    else if (x == 1) one++;
  }

  return (1LL << zero) * one;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << numberOfNearlyFullSequences() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1582/B