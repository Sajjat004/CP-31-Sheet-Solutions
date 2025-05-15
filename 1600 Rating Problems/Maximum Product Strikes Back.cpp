#include <bits/stdc++.h>
using namespace std;

array<int, 2> solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  
  auto maxProduct = [&] (int& left, int& right) -> int {
    int cnt2 = 0, cntNeg = 0;
    for (int i = left; i <= right; i++) {
      if (a[i] < 0) cntNeg++;
      if (abs(a[i]) == 2) cnt2++;
    }

    if (cntNeg % 2 == 0) return cnt2;
    int leftCnt2 = 0, rightCnt2 = 0;
    int leftIndex = left, rightIndex = right;
    
    for (int i = left; i <= right; i++) {
      if (abs(a[i]) == 2) leftCnt2++;
      leftIndex = i;
      if (a[i] < 0) break;
    }
    for (int i = right; i >= left; i--) {
      if (abs(a[i]) == 2) rightCnt2++;
      rightIndex = i;
      if (a[i] < 0) break;
    }

    if (leftCnt2 < rightCnt2) {
      left = leftIndex + 1;
      cnt2 -= leftCnt2;
    } else {
      right = rightIndex - 1;
      cnt2 -= rightCnt2;
    }

    return cnt2;
  };

  int maxCnt2 = 0, leftAns = 0, rightAns = n;
  int left = 1, right = 1;

  while (left <= n) {
    if (a[left] == 0) {
      left++;
      right = left;
      continue;
    }

    while (right <= n && a[right] != 0) {
      right++;
    }
    right--;

    if (left <= right) {
      int left1 = left, right1 = right;
      int cnt2 = maxProduct(left1, right1);
      if (cnt2 > maxCnt2) {
        maxCnt2 = cnt2;
        leftAns = left1 - 1;
        rightAns = n - right1;
      }
    }

    left = right + 1;
    right = left;
  }

  return {leftAns, rightAns};
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    auto result = solve();
    cout << result[0] << ' ' << result[1] << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1660/D
