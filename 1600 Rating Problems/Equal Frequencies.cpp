#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  vector<int> freq(26, 0);
  for (char c : s) {
    freq[c - 'a']++;
  }

  vector<pair<int, char>> freq_pairs;
  for (int i = 0; i < 26; i++) {
    if (freq[i] > 0) {
      freq_pairs.push_back({freq[i], 'a' + i});
    }
  }
  sort(freq_pairs.begin(), freq_pairs.end(), greater<pair<int, char>>());

  auto fun = [&] (int numberOfChar) -> int {
    int perCharacterFreq = n / numberOfChar;
    int index = 0;
    int minOperations = 0;

    for (int i = 1; i <= numberOfChar; ++i) {
      if (index < freq_pairs.size()) {
        if (freq_pairs[index].first < perCharacterFreq) {
          minOperations += perCharacterFreq - freq_pairs[index].first;
        }
        index++;
      } else {
        minOperations += perCharacterFreq;
      }
    }

    return minOperations;
  };

  int minOperations = INT_MAX;
  int numberOfChar = -1;
  for (int i = 1; i <= 26; ++i) {
    if (n % i != 0) continue;
    if (minOperations > fun(i)) {
      minOperations = fun(i);
      numberOfChar = i;
    }
  }

  int perCharacterFreq = n / numberOfChar;
  string result = s;
  if (numberOfChar < freq_pairs.size()) {
    for (int i = numberOfChar; i < freq_pairs.size(); ++i) {
      for (char& c : result) {
        if (c == freq_pairs[i].second) {
          c = '?';
        }
      }
    }
  }

  for (int i = 0; i < numberOfChar; ++i) {
    int limit = perCharacterFreq;
    if (i < freq_pairs.size()) {
      if (limit <= freq_pairs[i].first) {
        for (char& c : result) {
          if (c == freq_pairs[i].second) {
            if (limit > 0) limit--;
            else c = '?';
          }
        }
      } else {
        int need = limit - freq_pairs[i].first;
        for (char& c : result) {
          if (c == '?' and need > 0) {
            c = freq_pairs[i].second;
            need--;
          }
        }
      }
    } else {
      for (char c = 'a'; c <= 'z'; ++c) {
        if (freq[c - 'a'] == 0) {
          for (char& ch : result) {
            if (ch == '?' and limit > 0) {
              ch = c;
              limit--;
            }
          }
          freq[c - 'a'] = 1;
          break;
        }
      }
    }
  }

  cout << minOperations << '\n';
  cout << result << '\n';
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int tests; cin >> tests;
  while (tests--) {
    solve();
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1781/C
