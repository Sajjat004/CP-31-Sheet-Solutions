#include <bits/stdc++.h>
using namespace std;

bool isOddDivisorPresent() {
  long long n; cin >> n;

  while (n % 2 == 0 and n > 1) n /= 2;

  return n > 1;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (isOddDivisorPresent() ? "YES" : "NO") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1475/A