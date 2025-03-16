#include <bits/stdc++.h>
using namespace std;

bool makeAP() {
  int a, b, c; cin >> a >> b >> c;

  int newC = 2 * b - a;
  if (newC > 0 and newC % c == 0) return true;

  int newA = 2 * b - c;
  if (newA > 0 and newA % a == 0) return true; 

  int diff = c - a;
  if (diff & 1) return false;
  int newB = a + diff / 2;
  if (newB > 0 and newB % b == 0) return true;

  return false;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (makeAP() ? "YES" : "NO") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1624/B