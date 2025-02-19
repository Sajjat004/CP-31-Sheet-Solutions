#include <bits/stdc++.h>
using namespace std;

int minimumActions() {
  int n; cin >> n;
  string s; cin >> s;
  
  // Find the groups of empty cells in a row
  vector<int> emptyCellGroups;
  int count = 0, maxGroup = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '.') {
      count++;
    } else {
      if (count > 0) {
        emptyCellGroups.push_back(count);
        maxGroup = max(maxGroup, count);
        count = 0;
      }
    }
  }
  if (count > 0) {
    emptyCellGroups.push_back(count);
    maxGroup = max(maxGroup, count);
  }

  // If there is no empty cell, then we don't need to fill any cell with water
  if (emptyCellGroups.empty()) return 0;


  // If the size of the largest group is more than 2, then we need 2 actions of type 1 to fill it and the reaming groups can be filled with actions type 2.
  if (maxGroup > 2) return 2;

  // Otherwise we need to fill the each group separately
  int actions = 0;
  for (int x : emptyCellGroups) {
    if (x == 1) actions++;
    else actions += 2;
  }

  return actions;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int test; cin >> test;
  while (test--) {
    cout << minimumActions() << '\n';
  }
    
  return 0;
}