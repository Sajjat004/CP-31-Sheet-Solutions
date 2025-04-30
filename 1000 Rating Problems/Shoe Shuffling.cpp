#include <bits/stdc++.h>
using namespace std;

vector<int> solve() {
  int n; cin >> n;
  vector<pair<int, int>> s;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    s.push_back({x, i});
  }

  sort(s.begin(), s.end());

  vector<int> ans(n);
  int index = 0;

  while (index < n) {
    int j = index;
    while (j < n && s[j].first == s[index].first) {
      ++j;
    }

    if (j - index == 1) {
      return {-1};
    }

    for (int i = index; i < j; ++i) {
      ans[s[i].second] = s[i + 1].second + 1;
    }
    ans[s[j - 1].second] = s[index].second + 1;

    index = j;
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    vector<int> result = solve();
    for (int i = 0; i < result.size(); ++i) {
      cout << result[i] << ' ';
    }
    cout << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1691/B