#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int minOperation(string& num, char secondDigit, char firstDigit) {
  int lenght = num.size();
  int secondDigitIndex = -1, firstDigitIndex = -1;

  for (int i = lenght - 1; i >= 0; i--) {
    if (num[i] == firstDigit and firstDigitIndex == -1) {
      firstDigitIndex = i;
    } else if (num[i] == secondDigit and firstDigitIndex != -1) {
      secondDigitIndex = i;
      break;
    }
  }

  if (secondDigitIndex != -1) {
    return lenght - secondDigitIndex - 2;
  }

  return INT_MAX;
}

int minStepsToMakeDivisibleBy25() {
  ll n; cin >> n;
  string s = to_string(n);

  int operations = minOperation(s, '0', '0');
  operations = min(operations, minOperation(s, '2', '5'));
  operations = min(operations, minOperation(s, '5', '0'));
  operations = min(operations, minOperation(s, '7', '5'));

  return operations;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << minStepsToMakeDivisibleBy25() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1593/B