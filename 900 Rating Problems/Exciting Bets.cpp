#include <bits/stdc++.h>
using namespace std;

#define ll long long

pair<ll, ll> getMaximumGCD() {
  ll a, b;
  cin >> a >> b;
  if (a > b) swap(a, b);

  if (a == b) return {0, 0};

  return {b - a, min(a % (b - a), (b - a) - a % (b - a))};
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    pair<ll, ll> result = getMaximumGCD();
    cout << result.first << ' ' << result.second << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1543/A