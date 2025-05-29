#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<int> perfectSquares;
vector<int> freq(1 << 19, 0);
void precompute() {
  for (int i = 1; i * i < (1 << 19); i++) {
    perfectSquares.push_back(i * i);
  }
}

void solution() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  freq[0] = 1;
  ll ans = 0;
  int XOR = 0;
  for (int i = 0; i < n; ++i) {
    XOR ^= a[i];
    int subArrays = i + 1;
    for (int sq : perfectSquares) {
      int target = XOR ^ sq;
      subArrays -= freq[target];
    }
    
    subArrays -= freq[XOR];
    ans += subArrays;
    freq[XOR]++;
  }

  cout << ans << '\n';

  XOR = 0;
  freq[XOR] = 0;
  for (int i = 0; i < n; ++i) {
    XOR ^= a[i];
    freq[XOR] = 0;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  precompute();
  int tests; cin >> tests;
  while (tests--) {
    solution();
  }

  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1731/C