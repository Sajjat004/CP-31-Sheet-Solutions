#include <bits/stdc++.h>
using namespace std;

string makeBalance() {
  string s; cin >> s;
  // If the first character and last character are the same, then AB(S) = BA(S)
  s[0] = s[s.size() - 1];

  return s;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << makeBalance() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1606/A