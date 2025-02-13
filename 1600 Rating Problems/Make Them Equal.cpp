#include <bits/stdc++.h>
using namespace std;

vector<int> getMinOperations(int n) {
  vector<int> dp(n + 1, 1e9);
  dp[1] = 0;
  for (int i = 1; i <= n; ++i) {
    for (int x = 1; x <= i; ++x) {
      int jump = i + i / x;

      if (jump <= n) {
        dp[jump] = min(dp[jump], dp[i] + 1);
      }
    }
  }

  return dp;
}

long long dpCall(int pos, int k, vector<int>& coin, vector<int>& b, vector<int>& minOperations, vector<vector<long long>>& dp) {
  if (pos == b.size()) return 0;
  if (dp[pos][k] != -1) return dp[pos][k];

  long long ans = dpCall(pos + 1, k, coin, b, minOperations, dp);
  if (k >= minOperations[b[pos]]) {
    ans = max(ans, coin[pos] + dpCall(pos + 1, k - minOperations[b[pos]], coin, b, minOperations, dp));
  }

  return dp[pos][k] = ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  vector<int> minOperations = getMinOperations(1000);

  int test; cin >> test;
  while (test--) {
    int n, k; cin >> n >> k;
    vector<int> b(n), coin(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> coin[i];

    int sumOfOperations = 0;
    for (int i = 0; i < n; ++i) {
      sumOfOperations += minOperations[b[i]];
    }

    k = min(k, sumOfOperations);
    vector<vector<long long>> dp(n, vector<long long>(k + 1, -1));

    cout << dpCall(0, k, coin, b, minOperations, dp) << '\n';
  }
    
  return 0;
}