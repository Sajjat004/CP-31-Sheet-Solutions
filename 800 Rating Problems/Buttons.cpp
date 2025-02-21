#include <bits/stdc++.h>
using namespace std;

string getWinner(int a, int b, int c) {
  a += (c + 1) / 2;
  b += c / 2;
  
  return a > b ? "First" : "Second";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int a, b, c; cin >> a >> b >> c;

    cout << getWinner(a, b, c) << '\n';
  }
    
  return 0;
}

// Problem Link:https://codeforces.com/problemset/problem/1858/A