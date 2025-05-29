#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> divisors[N];

void precompute() {
  for (int i = 1; i < N; i++) {
    for (int j = i; j < N; j += i) {
      divisors[j].push_back(i);
    }
  }
}

void quizMaster() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  auto isValid = [&](int k) -> bool {
    vector<int> cnt(m + 1, 0);
    int divCnt = 0;

    for (int left = 0, right = 0; right < n; ++left) {
      while (right < n and a[right] - a[left] <= k) {
        for (int d : divisors[a[right]]) {
          if (d <= m) {
            cnt[d]++;
            if (cnt[d] == 1) divCnt++;
          }
        }
        right++;
      }
      if (divCnt >= m) return true;
      for (int d : divisors[a[left]]) {
        if (d <= m) {
          cnt[d]--;
          if (cnt[d] == 0) divCnt--;
        }
      }
    }

    return false;
  };

  int left = 0, right = 1e5;
  int ans = -1;
  while (left <= right) {
    int mid = (left + right) / 2;
    if (isValid(mid)) {
      ans = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  cout << ans << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  precompute();
  int tests; cin >> tests;
  while (tests--) {
    quizMaster();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1777/C
