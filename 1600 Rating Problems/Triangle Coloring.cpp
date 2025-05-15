#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

class Math {
  int expo(int base, int exp, const int mod) {
    int res = 1 % mod;
    base %= mod;
    if (base < 0) base += mod;
    while (exp) {
      if (exp & 1) res = 1LL * res * base % mod;
      base = 1LL * base * base % mod;
      exp >>= 1;
    }
    return res;
  }

  int modinv(int x, int mod) {
    return expo(x, mod - 2, mod);
  }

  vector<int> fact, invfact;
public:
  Math(int n) {
    fact.resize(n);
    invfact.resize(n);
    fact[0] = invfact[0] = 1;
    for (int i = 1; i < n; i++) {
      fact[i] = (1LL * i * fact[i - 1]) % MOD;
      invfact[i] = modinv(fact[i], MOD);
    }
  }

  int ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    int ans = fact[n];
    ans = (1LL * ans * invfact[n - r]) % MOD;
    ans = (1LL * ans * invfact[r]) % MOD;
    return ans;
  }
};

int solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int ans = 1;
  vector<int> v;
  for (int i = 0; i < n; ++i) {
    v.push_back(a[i]);
    
    if (v.size() == 3) {
      sort(v.begin(), v.end());
      if (v[0] == v[2]) {
        ans = (1LL * ans * 3) % MOD;
      } else if (v[0] == v[1]) {
        ans = (1LL * ans * 2) % MOD;
      }
      v.clear();
    }
  }

  Math math(n + 1);
  ans = (1LL * ans * math.ncr(n / 3, n / 6)) % MOD;

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cout << solve() << '\n';
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1795/D