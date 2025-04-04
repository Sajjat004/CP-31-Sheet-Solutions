#include <bits/stdc++.h>
using namespace std;

int moveBrackets() {
  int n; cin >> n;
  string s; cin >> s;

  stack<char> bracketStack;

  for (int i = 0; i < n; ++i) {
    if (s[i] == ')' and !bracketStack.empty() and bracketStack.top() == '(') {
      bracketStack.pop();
    } else {
      bracketStack.push(s[i]);
    }
  }

  return bracketStack.size() / 2;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << moveBrackets() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1374/C