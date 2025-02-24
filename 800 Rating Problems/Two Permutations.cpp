#include <bits/stdc++.h>
using namespace std;

bool isPermutationExist() {
  int n, a, b; cin >> n >> a >> b;

  if (a == n and b == n) return true;
  if ((a + b) < n) return true;
  if ((a + b) == n and n % 2 == 0) return true;

  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (isPermutationExist() ? "Yes" : "No") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1761/A