#include <bits/stdc++.h>
using namespace std;

int solve() {
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  vector<pair<int, int>> affinitySegment;
  for (int i = 0; i < n; ++i) {
    affinitySegment.push_back({a[i] - x, a[i] + x});
  }

  int left = affinitySegment[0].first;
  int right = affinitySegment[0].second;
  int changeOfAffinity = 0;

  for (int i = 1; i < n; ++i) {
    left = max(left, affinitySegment[i].first);
    right = min(right, affinitySegment[i].second);

    if (left > right) {
      changeOfAffinity++;
      left = affinitySegment[i].first;
      right = affinitySegment[i].second;
    }
  }

  return changeOfAffinity;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1704/B