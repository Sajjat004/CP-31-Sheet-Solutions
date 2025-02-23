#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    long long n, k; cin >> n >> k;
    long long reminder = n % k;

    bool possible = false;
    if (reminder % 2 == 0) possible = true;
    if (reminder & 1 and k & 1) possible = true;

    cout << (possible ? "YES" : "NO") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1814/A