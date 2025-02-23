#include <bits/stdc++.h>
using namespace std;

int minimumOperations(int n, vector<int> &a) {
  
  int positiveOne = 0, negativeOne = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) positiveOne++;
    else negativeOne++;
  }

  int operations = 0;

  if (positiveOne >= negativeOne) {
    if (negativeOne & 1) operations = 1;
  } else {
    int diff = (negativeOne - positiveOne + 1) / 2;
    operations = diff;
    negativeOne -= diff;
    if (negativeOne & 1) operations += 1;
  }

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    cout << minimumOperations(n, a) << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1834/A