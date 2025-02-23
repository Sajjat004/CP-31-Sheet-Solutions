#include <bits/stdc++.h>
using namespace std;

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    string s; cin >> s;

    int ogirinalLength = n;
    int left = 0, right = n - 1;

    while (s[left] != s[right] and left < right) {
      ogirinalLength -= 2;
      left++;
      right--;
    }

    cout << ogirinalLength << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1791/C