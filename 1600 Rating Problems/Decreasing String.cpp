#include <bits/stdc++.h>
using namespace std;

string getStringFromStack(stack<char>& st) {
  string s = "";
  while (!st.empty()) {
    s += st.top();
    st.pop();
  }

  reverse(s.begin(), s.end());

  return s;
}

char solve() {
  string s; cin >> s;
  long long k; cin >> k;
  int n = s.size();

  int operations = 0;
  long long m = n;
  while (k > m) {
    k -= m;
    m--;
    operations++;
  }

  stack<char> st;
  for (char ch : s) {
    while (!st.empty() and st.top() > ch and operations > 0) {
      st.pop();
      operations--;
    }
    st.push(ch);
  }

  string t = getStringFromStack(st);
  return t[k - 1];
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve();
  }
  cout << '\n';
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1886/C
