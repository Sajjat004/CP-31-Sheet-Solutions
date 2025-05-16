#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll power(ll base, int exp) {
  ll result = 1;

  while (exp > 0) {
    if (exp % 2 == 1) {
      result *= base;
    }
    base *= base;
    exp /= 2;
  }

  return result;
}

vector<int> spf(200001, 0);
vector<int> primes;

vector<int> smallestPrimeFactors(int n) {
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


ll solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int& x : a) cin >> x;

  vector<vector<int>> primeFactors(200001);
  set<int> factors;
  smallestPrimeFactors(200000);
  
  for (int i = 0; i < n; ++i) {
    int x = a[i];
    while (x > 1) {
      int factor = spf[x];
      int cnt = 0;
      while (x % factor == 0) {
        x /= factor;
        cnt++;
      }
      primeFactors[factor].push_back(cnt);
    }
  }

  ll ans = 1;
  for (int prime: primes) {
    if (prime > 200000) break;
    sort(primeFactors[prime].begin(), primeFactors[prime].end());

    if (primeFactors[prime].size() == n) ans *= power(prime, primeFactors[prime][1]);
    else if (primeFactors[prime].size() == n - 1) ans *= power(prime, primeFactors[prime][0]);
  }

  return ans;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  cout << solve() << '\n';
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1349/A