#include <bits/stdc++.h>
using namespace std;

int getValueInRigs(vector<string>& s, int ring) {
  int value = 0;
  for (int i = ring; i < 10 - ring; ++i) {
    // left count
    value += s[i][ring] == 'X';
    // right count
    value += s[i][9 - ring] == 'X';
    // top count
    value += s[ring][i] == 'X';
    // bottom count
    value += s[9 - ring][i] == 'X';
  }

  // remove overlapping corners
  value -= (s[ring][ring] == 'X');
  value -= (s[ring][9 - ring] == 'X');
  value -= (s[9 - ring][ring] == 'X');
  value -= (s[9 - ring][9 - ring] == 'X');

  return value;
}

int getPoints(vector<string>& s) {
  int points = 0;
  for (int i = 1; i <= 5; ++i) {
    points += (i * getValueInRigs(s, i - 1));
  }

  return points;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    vector<string> s(10);
    for (int i = 0; i < 10; ++i) {
      cin >> s[i];
    }

    cout << getPoints(s) << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1873/C