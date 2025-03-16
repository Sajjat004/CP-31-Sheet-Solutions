#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll findGrasshopper() {
  ll initialPosition, numberOfJump; cin >> initialPosition >> numberOfJump;
  
  // After every 4 jumps, the grasshopper will return to the initial position.
  ll jump = (numberOfJump / 4) * 4;
  for (++jump; jump <= numberOfJump; ++jump) {
    if (initialPosition & 1) initialPosition += jump;
    else initialPosition -= jump;
  }

  return initialPosition;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << findGrasshopper() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1607/B