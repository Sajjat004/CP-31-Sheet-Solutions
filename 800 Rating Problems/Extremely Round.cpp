#include <bits/stdc++.h>
using namespace std;

int numberWithZerroAtEnd(int start, int endZerro) {
  for (int i = 1; i <= endZerro; ++i) {
    start *= 10;
  }

  return start;
}

int extremlyRound() {
  int n; cin >> n;
  int ans = 0;

  for (int endZerro = 0; endZerro < 7; ++endZerro) {
    for (int start = 1; start < 10; ++start) {
      if (numberWithZerroAtEnd(start, endZerro) <= n) {
        ans++;
      }
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << extremlyRound() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1766/A