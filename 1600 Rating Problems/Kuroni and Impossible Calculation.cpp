#include <bits/stdc++.h>
using namespace std;

int add(int a, int b, const int mod) { return (a + b) % mod; }
int subtract(int a, int b, const int mod) { return (a - b + mod) % mod; }
int multiply(int a, int b, const int mod) { return 1LL * a * b % mod; }

int solve() {
  int n, mod; cin >> n >> mod;
  vector<int> freq(mod + 1, 0);
  vector<int> arr(n);
  bool haveMoreThanOne = false;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    arr[i] = x;
    freq[x % mod]++;
    if (freq[x % mod] > 1) {
      haveMoreThanOne = true;
    }
  }

  if (haveMoreThanOne) return 0;

  int ans = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      ans = multiply(ans, abs(arr[i] - arr[j]), mod);
    }
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cout << solve() << '\n';
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1305/C
