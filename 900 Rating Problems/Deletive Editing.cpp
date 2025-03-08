#include <bits/stdc++.h>
using namespace std;

bool solve() {
  string s, t; cin >> s >> t;
  int n = s.size(), m = t.size();
  int index1 = n - 1, index2 = m - 1;
  vector<bool> visited(26, false);

  while (index2 >= 0) {
    while (index1 >= 0 and s[index1] != t[index2]) {
      visited[s[index1] - 'A'] = true;
      index1--;
    }

    if (index1 < 0) return false;
    if (visited[s[index1] - 'A']) return false;
    index1--;
    index2--;
  }

  return true;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (solve() ? "YES" : "NO") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1666/D