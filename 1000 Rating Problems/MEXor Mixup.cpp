#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 5;

int solve(vector<int>& XOR) {
  int a, b; cin >> a >> b;
  int lastValue = b ^ XOR[a - 1];

  if (lastValue == 0) return a;
  if (lastValue == a) return a + 2;

  return a + 1;
}

void getXOR(vector<int>& XOR) {
  XOR[0] = 0;
  for (int i = 1; i < XOR.size(); ++i) {
    XOR[i] = XOR[i - 1] ^ i;
  }
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  vector<int> XOR(N);
  getXOR(XOR);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << solve(XOR) << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1567/B