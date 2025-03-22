#include <bits/stdc++.h>
using namespace std;

int solve() {
  string s; cin >> s;
  int ones = 0, zeros = 0;
  for (char c : s) {
    if (c == '1') ones++;
    else zeros++;
  }

  for (char x : s) {
    if (x == '1' and zeros > 0) zeros--;
    else if (x == '0' and ones > 0) ones--;
    else break;
  }

  return ones + zeros;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1913/B