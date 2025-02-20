#include <bits/stdc++.h>
using namespace std;

int frequencyDifference(int n, vector<int> &a) {
  unordered_map<int, int> frequency;
  for (int i = 0; i < n; ++i) {
    frequency[a[i]]++;
  }
  sort(a.begin(), a.end());

  return abs(frequency[a[0]] - frequency[a[n - 1]]);
}

int getUniuqeElements(vector<int> &a) {
  unordered_set<int> uniqueElements;
  for (int i = 0; i < a.size(); ++i) {
    uniqueElements.insert(a[i]);
  }

  return uniqueElements.size();
}

bool isGoodArray(int n, vector<int> &a) {
  int uniqueElements = getUniuqeElements(a);

  if (uniqueElements > 2) return false;
  if (uniqueElements == 1) return true;

  return frequencyDifference(n, a) <= 1;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    cout << (isGoodArray(n, a) ? "Yes" : "No") << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1890/A