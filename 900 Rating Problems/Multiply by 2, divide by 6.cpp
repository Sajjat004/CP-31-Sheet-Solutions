#include <bits/stdc++.h>
using namespace std;

int findMoves() {
  int n; cin >> n;

  if (n == 1) return 0;
  if (n % 3 != 0) return -1;

  int moves = 0;
  while (n > 1) {
    if (n % 3 != 0) return -1;
    if (n % 6 == 0) {
      n /= 6;
      moves++;
    } else {
      n *= 2;
      moves++;
    }
  }

  return moves;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << findMoves() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1374/B