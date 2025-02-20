#include <bits/stdc++.h>
using namespace std;

string winner(int n) {
  // If n is divisible by 3, then the second player will win because the first player will have to subtract 1 or add 1, then the second player make the oppsite move. Doing this process, 10 moves passed.
  if (n % 3 == 0) return "Second";
  // If n is not divisible by 3, then the remiander of n divided by 3 is 1 or 2. So, by one move, the first player can make n divisible by 3.
  return "First";
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    int n; cin >> n;

    cout << winner(n) << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1899/A