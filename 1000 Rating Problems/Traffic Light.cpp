#include <bits/stdc++.h>
using namespace std;

int minimumTimeToCrossTheRoad() {
  int n; cin >> n;
  char currentLight; cin >> currentLight;
  string lights; cin >> lights;
  lights = lights + lights;

  int minimumTme = 0;
  int lastGreen = -1;

  for (int i = (2 * n) - 1; i >= 0; --i) {
    if (lights[i] == currentLight) {
      minimumTme = max(minimumTme, lastGreen - i);
    } else if (lights[i] == 'g') {
      lastGreen = i;
    }
  }

  return minimumTme;
}

int32_t main() {
  ios_base::sync_with_stdio(false); cin.tie(0);

  int testCases; cin >> testCases;
  while (testCases--) {
    cout << minimumTimeToCrossTheRoad() << '\n';
  }
    
  return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1744/C