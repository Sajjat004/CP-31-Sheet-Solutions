#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> numberOfBuses() {
  long long wheels; cin >> wheels;
  if (wheels < 4) return {-1, -1};
  if (wheels & 1) return {-1, -1};

  ll minimumBus = wheels / 6;
  if (wheels % 6 == 4) minimumBus++;
  else if (wheels % 6 == 2 and minimumBus > 0) minimumBus++;
  else if (wheels % 6 == 2 and minimumBus == 0) minimumBus = 2;

  ll maximumBus = wheels / 4;

  return {minimumBus, maximumBus};
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    vector<ll> minMaxBus = numberOfBuses();
    ll minimumBus = minMaxBus[0];
    ll maximumBus = minMaxBus[1];

    cout << minimumBus;
    if (maximumBus != -1) cout << ' ' << maximumBus;
    cout << '\n';
  }
    
  return 0;
}