#include <bits/stdc++.h>
using namespace std;

bool checkSubString(string x, string s) {
  if (x.find(s) == string::npos) return false;

  return true;
}

int minimumOperations() {
  int n, m; cin >> n >> m;
  string x, s; cin >> x >> s;
  int operations = 0;
  do {
    if (checkSubString(x, s)) return operations;
    x += x;
    operations++;
  } while (x.size() < 50);

  return -1;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << minimumOperations() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1881/A