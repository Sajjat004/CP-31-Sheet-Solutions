#include <bits/stdc++.h>
using namespace std;

array<int, 4> yoyoPositions() {
  int n, m, x, y; cin >> n >> m >> x >> y;

  // Two conrers from the (x, y) point is always the maximum distance
  return {1, 1, n, m};
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    array<int, 4> positions = yoyoPositions();
    cout << positions[0] << ' ' << positions[1] << ' ' << positions[2] << ' ' << positions[3] << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1537/B