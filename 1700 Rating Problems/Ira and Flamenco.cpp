#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int MOD = 1e9 + 7;

int add(int a, int b) { return (a + b) % MOD; }
int subtract(int a, int b) { return (a - b + MOD) % MOD; }
int multiply(int a, int b) { return 1LL * a * b % MOD; }

int power(int base, int exp) {
  int res = 1 % MOD;
  base %= MOD;
  if (base < 0) base += MOD;

  while (exp) {
    if (exp & 1) res = 1LL * res * base % MOD;
    base = 1LL * base * base % MOD;
    exp >>= 1;
  }

  return res;
}

void flamencoDance() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  map<int, int> freq;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    freq[a[i]]++;
  }
  sort(a.begin(), a.end());
  a.erase(unique(a.begin(), a.end()), a.end());

  if (m > (int) a.size()) {
    cout << "0\n";
    return;
  }

  int magnificentheoryDances = 0;
  
  int left = 0, right = m - 1;
  int product = 1;

  for (int i = 0; i < m; ++i) {
    product = multiply(product, freq[a[i]]);
  }

  while (right < (int) a.size()) {
    if (abs(a[right] - a[left]) < m) {
      magnificentheoryDances = add(magnificentheoryDances, product);
    }

    product = multiply(product, power(freq[a[left]], MOD - 2));
    left++;
    right++;
    if (right < (int) a.size()) {
      product = multiply(product, freq[a[right]]);
    }
  }

  cout << magnificentheoryDances << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    flamencoDance();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1833/F