#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a;

  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    a.push_back({x, i + 1});
  }
  sort(a.begin(), a.end());

  vector<int> ans(n + 1, 0);
  ans[0] = 0;
  int coordinate = 1;
  bool positive = true;

  for (int i = n - 1; i >= 0; --i) {
    ans[a[i].second] = coordinate;
    if (positive) {
      coordinate *= -1;
      positive = false;
    } else {
      coordinate *= -1;
      positive = true;
      coordinate++;
    }
  }

  ll distances = 0;
  for (int i = 1; i <= n; ++i) {
    distances += 1LL * a[i - 1]
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
    
  return 0;
}