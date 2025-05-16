#include <bits/stdc++.h>
using namespace std;

class GCDSparseTable {
  vector<vector<int>> sparseTable;
  int n;

  void build(const vector<int>& arr) {
    for (int i = 1; i <= n; ++i) {
      sparseTable[0][i] = arr[i - 1];
    }

    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
        sparseTable[j][i] = __gcd(sparseTable[j - 1][i], sparseTable[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

public:
  GCDSparseTable(const vector<int>& arr) {
    n = arr.size();
    int logN = n == 0 ? 0 : log2(n) + 1;
    sparseTable.resize(logN + 5, vector<int>(n + 5, 0));

    build(arr);
  }

  int query(int l, int r) {
    int j = log2(r - l + 1);
    return __gcd(sparseTable[j][l], sparseTable[j][r - (1 << j) + 1]);
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vector<int> arr(n);
  for (int& x : arr) { cin >> x; }

  vector<int> diff;
  for (int i = 1; i < n; ++i) {
    diff.push_back(abs(arr[i] - arr[i - 1]));
  }

  GCDSparseTable gcdSparseTable(diff);

  while (q--) {
    int l, r; cin >> l >> r;

    if (l == r) {
      cout << 0 << ' ';
      continue;
    }

    int gcd = gcdSparseTable.query(l, r - 1);
    cout << gcd << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/2050/F

// Key Insight
// If we have two numbers x and y and we want to find the maximum modulo of x and y so that x mod m = y mod m
// Here, x mod m = y mod m
// => |x - y| mod m = 0
// So, all the divisors of |x - y| are the possible values of m.