#include <bits/stdc++.h>
using namespace std;

string winner() {
  string s; cin >> s;

  int zero = 0, one = 0;

  for (int i = 0; i < s.size(); ++i) {
    if (s[i] == '1') {
      one++;
    } else {
      zero++;
    }
  }

  return (min(zero, one) % 2 == 0) ? "NET" : "DA";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << winner() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1373/B