#include <bits/stdc++.h>
using namespace std;

int solve() {
  int a, b; cin >> a >> b;

  int operations = INT_MAX;
  
  for (int i = max(2, b); ; i++) {
    int x = a;
    int count = i - b;
    while (x > 0) {
      x /= i;
      count++;
    }

    if (count <= operations) {
      operations = count;
    } else {
      break;
    }
  }

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1485/A