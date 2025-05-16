#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

class NumberTheory {
  vector<int> factorial;
  vector<int> inverseFactorial;

public:
  int add(int a, int b, const int mod) { return (a + b) % mod; }
  int subtract(int a, int b, const int mod) { return (a - b + mod) % mod; }
  int multiply(int a, int b, const int mod) { return 1LL * a * b % mod; }

  int power(int base, int exp, const int mod) {
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

  int modInverse(int a, const int mod) {
    return power(a, mod - 2, mod);
  }

  void buildFactorial(int n, const int mod) {
    factorial.resize(n + 1);
    inverseFactorial.resize(n + 1);

    factorial[0] = 1;
    factorial[1] = 1;

    for (int i = 2; i <= n; ++i) {
      factorial[i] = 1LL * factorial[i - 1] * i % mod;
    }

    inverseFactorial[n] = power(factorial[n], mod - 2, mod);
    for (int i = n - 1; i >= 0; --i) {
      inverseFactorial[i] = 1LL * inverseFactorial[i + 1] * (i + 1) % mod;
    }
  }

  int getFactorial(int n) { return factorial[n]; }
  int getInverseFactorial(int n) { return inverseFactorial[n]; }

  // Before using this function, you need to call buildFactorial(n, mod)
  int getCombination(int n, int k, const int mod) {
    if (k < 0 || k > n) return 0;
    return 1LL * factorial[n] * inverseFactorial[k] % mod * inverseFactorial[n - k] % mod;
  }
  
  vector<int> smallestPrimeFactors(int n) {
    vector<int> spf(n + 1, 0);
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
      if (spf[i] == 0) {
        spf[i] = i;
        primes.push_back(i);
      }

      for (int j = 0; j < (int)primes.size() && primes[j] <= spf[i] && i * primes[j] <= n; j++) {
        spf[i * primes[j]] = primes[j];
      }
    }

    return spf;
  }

  vector<int> linearSieve(int n) {
    vector<int> spf(n + 1, 0);
    vector<int> primes;

    for (int i = 2; i <= n; i++) {
      if (spf[i] == 0) {
        spf[i] = i;
        primes.push_back(i);
      }

      for (int j = 0; j < (int)primes.size() && primes[j] <= spf[i] && i * primes[j] <= n; j++) {
        spf[i * primes[j]] = primes[j];
      }
    }

    return primes;
  }
};

int solve() {
  int n, k; cin >> n >> k;
  map<int, int> freq;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    freq[x]++;
    a[i] = x;
  }

  sort(a.begin(), a.end(), greater<int>());
  int maxFollowers = 0;
  for (int i = 0; i < k; ++i) {
    maxFollowers += a[i];
  }

  int lastValueCount = 0;
  for (int i = 0; i < k; ++i) {
    if (a[i] == a[k - 1]) {
      lastValueCount++;
    }
  }

  NumberTheory ntheory;
  ntheory.buildFactorial(n, MOD);

  int totalWays = ntheory.getCombination(freq[a[k - 1]], lastValueCount, MOD);

  return totalWays;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    cout << solve() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1475/E
