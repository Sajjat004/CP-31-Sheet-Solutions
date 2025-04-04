#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool isFair(ll n) {
  string s = to_string(n);
  for (char c : s) {
    int digit = c - '0';
    if (digit != 0 and n % digit != 0) return false;
  }

  return true;
}

ll findFairNumber() {
  ll n; cin >> n;

  while (true) {
    if (isFair(n)) return n;
    n++;
  }

  return -1; // This line will never be reached
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << findFairNumber() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1411/B