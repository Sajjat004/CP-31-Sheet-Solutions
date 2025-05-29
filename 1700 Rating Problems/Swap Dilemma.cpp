#include <bits/stdc++.h>
using namespace std;

class InversionCount {
  long long inversions = 0;

  void merge(vector<int>& nums, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> leftArr(n1);
    vector<int> rightArr(n2);

    for (int i = 0; i < n1; i++) leftArr[i] = nums[left + i];
    for (int j = 0; j < n2; j++) rightArr[j] = nums[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 and j < n2) {
      if (leftArr[i] <= rightArr[j]) {
        nums[k++] = leftArr[i++];
      } else {
        nums[k++] = rightArr[j++];
        inversions += (n1 - i);
      }
    }

    while (i < n1) { nums[k++] = leftArr[i++]; }
    while (j < n2) { nums[k++] = rightArr[j++]; }
  }

  void partition(vector<int>& nums, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    partition(nums, left, mid);
    partition(nums, mid + 1, right);
    merge(nums, left, mid, right);
  }

public:
  long long countInversions(vector<int>& nums) {
    inversions = 0;
    partition(nums, 0, nums.size() - 1);
    return inversions;
  }
};

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int& x : a) cin >> x;
  for (int& x : b) cin >> x;

  vector<int> c = a;
  vector<int> d = b;
  sort(c.begin(), c.end());
  sort(d.begin(), d.end());

  if (c != d) {
    cout << "NO\n";
    return;
  }

  InversionCount ic;
  long long invA = ic.countInversions(a);
  long long invB = ic.countInversions(b);

  cout << (invA % 2 == invB % 2 ? "YES" : "NO") << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1983/D
