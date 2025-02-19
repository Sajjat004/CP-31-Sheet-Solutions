#include <bits/stdc++.h>
using namespace std;

bool checkPossibility(int countPlus, int countMinus, int a, int b) {
  if (countPlus == countMinus) return true;
  if (a == b) return false;

  long long diff = countPlus - countMinus;
  return ((diff * b) % (b - a) == 0) and (1LL * diff * b) / (b - a) >= -countMinus and (1LL * diff * b) / (b - a) <= countPlus;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int n; cin >> n;
  string s; cin >> s;
  int countPlus = 0, countMinus = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '+') {
      countPlus++;
    } else {
      countMinus++;
    }
  }

  int q; cin >> q;
  while (q--) {
    int a, b; cin >> a >> b;

    cout << (checkPossibility(countPlus, countMinus, a, b) ? "Yes" : "No") << '\n';
  }
    
  return 0;
}