#include <bits/stdc++.h>
using namespace std;

bool isPalindromeAfterRomoval() {
  int n, k; cin >> n >> k;
  string s; cin >> s;

  vector<int> frequency(26, 0);
  for (char c : s) {
    frequency[c - 'a']++;
  }

  int oddCount = 0;
  for (int i = 0; i < 26; i++) {
    if (frequency[i] % 2 != 0) {
      oddCount++;
    }
  }

  oddCount = oddCount - min(oddCount, k);
  return oddCount <= 1;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << (isPalindromeAfterRomoval() ? "YES" : "NO") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1883/B