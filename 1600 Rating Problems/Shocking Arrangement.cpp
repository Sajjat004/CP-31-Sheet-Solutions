#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> positive, negative;
  int countZero = 0;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x;
    if (x >= 0) positive.push_back(x);
    else negative.push_back(x);

    if (x == 0) countZero++;
  }

  if (countZero == n) {
    cout << "No" << '\n';
    return;
  }

  long long sum = 0;
  vector<int> result;
  sort(positive.begin(), positive.end());
  sort(negative.begin(), negative.end(), greater<int>());

  int posIndex = positive.size() - 1;
  int negIndex = negative.size() - 1;

  while (posIndex >= 0 or negIndex >= 0) {
    if (sum > 0 and negIndex >= 0) {
      result.push_back(negative[negIndex]);
      sum += negative[negIndex];
      negIndex--;
    } else if (sum < 0 and posIndex >= 0) {
      result.push_back(positive[posIndex]);
      sum += positive[posIndex];
      posIndex--;
    } else if (posIndex >= 0) {
      result.push_back(positive[posIndex]);
      sum += positive[posIndex];
      posIndex--;
    } else if (negIndex >= 0) {
      result.push_back(negative[negIndex]);
      sum += negative[negIndex];
      negIndex--;
    }
  }

  cout << "Yes" << '\n';
  for (int i = 0; i < result.size(); ++i) {
    cout << result[i] << ' ';
  }
  cout << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1798/D
