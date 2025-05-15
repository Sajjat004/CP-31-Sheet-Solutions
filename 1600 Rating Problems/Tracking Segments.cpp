#include <bits/stdc++.h>
using namespace std;

struct Segment {
  int left, right;
  Segment(int l, int r) : left(l), right(r) {}
};

int solve() {
  int n, m; cin >> n >> m;
  vector<Segment> segments;
  for (int i = 0; i < m; ++i) {
    int l, r; cin >> l >> r;
    segments.push_back({l, r});
  }

  int q; cin >> q;
  vector<int> queries(q);
  for (int i = 0; i < q; ++i) {
    cin >> queries[i];
  }

  auto isBeautiful = [&] (int k) -> bool {
    vector<bool> isOne(n + 1, false);
    for (int i = 0; i < k; ++i) {
      isOne[queries[i]] = true;
    }

    vector<int> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
      prefixSum[i] = prefixSum[i - 1] + isOne[i];
    }

    for (const auto& seg : segments) {
      int l = seg.left, r = seg.right;
      int ones = prefixSum[r] - prefixSum[l - 1];
      int zeros = (r - l + 1) - ones;
      if (ones > zeros) return true;
    }

    return false;
  };

  int left = 1, right = q;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (isBeautiful(mid)) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return left == (q + 1) ? -1 : left;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1843/E
