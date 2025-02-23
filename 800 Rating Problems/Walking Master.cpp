#include <bits/stdc++.h>
using namespace std;

int minimumMoves() {
  int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

  if (y2 >= y1) {
    int yAxisDiff = y2 - y1;
    int newX = x2 - yAxisDiff;
    int newY = y1;

    if (newX > x1) return -1;

    return yAxisDiff + x1 - newX;
  }

  return -1;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << minimumMoves() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1806/A