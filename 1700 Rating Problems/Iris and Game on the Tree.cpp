#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n; cin >> n;
  vector<int> degree(n + 1);
  for (int i = 1; i < n; ++i) {
    int u, v; cin >> u >> v;
    degree[u]++;
    degree[v]++;
  }
  string s; cin >> s; s = "$" + s;
  int onesInLiaf = 0, zerosInLiaf = 0, questionMarksInLiaf = 0, internalQuestionMarks = 0;
  for (int i = 2; i <= n; ++i) {
    if (degree[i] == 1) {
      if (s[i] == '1') onesInLiaf++;
      else if (s[i] == '0') zerosInLiaf++;
      else questionMarksInLiaf++;
    } else {
      if (s[i] == '?') internalQuestionMarks++;
    }
  }

  if (s[1] == '1') {
    return zerosInLiaf + (questionMarksInLiaf + 1) / 2;
  } else if (s[1] == '0') {
    return onesInLiaf + (questionMarksInLiaf + 1) / 2;
  }

  if (onesInLiaf != zerosInLiaf) {
    return max(onesInLiaf, zerosInLiaf) + (questionMarksInLiaf) / 2;
  }

  return onesInLiaf + ((internalQuestionMarks & 1) ? (questionMarksInLiaf + 1) / 2 : questionMarksInLiaf / 2);
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/2006/A
