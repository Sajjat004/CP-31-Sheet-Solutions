#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b, const int mod) { return (a + b) % mod; }
int subtract(int a, int b, const int mod) { return (a - b + mod) % mod; }
int multiply(int a, int b, const int mod) { return (1LL * a * b) % mod; }

void sumOfXORFuncton() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int xorSum = 0;
  for (int bit = 0; bit < 30; ++bit) {
    int curSum = 0;
    vector<int> sumOfLeft(2);
    vector<int> count(2);
    count[0] = 1;
    bool parity = 0;

    for (int i = 0; i < n; ++i) {
      parity ^= ((a[i] >> bit) & 1);
      int sumOfRight = multiply(count[parity ^ 1], i + 1, MOD);
      curSum = add(curSum, subtract(sumOfRight, sumOfLeft[parity ^ 1], MOD), MOD);

      ++count[parity];
      sumOfLeft[parity] = add(sumOfLeft[parity], i + 1, MOD);
    }

    xorSum = add(xorSum, multiply(curSum, (1 << bit), MOD), MOD);
  }

  cout << xorSum << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);
  
  sumOfXORFuncton();

  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1879/D