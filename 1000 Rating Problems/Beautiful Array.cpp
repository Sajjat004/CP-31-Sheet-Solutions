#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> solve() {
	ll n, k, b, s; cin >> n >> k >> b >> s;

	vector<ll> result(n, 0);
	result[0] = (b * k);
	s -= (b * k);
	for (int i = 1; i < n; ++i) {
		if (s > 0) {
			result[i] = min(k - 1, s);
			s -= result[i];
		}
	}

	if (s > 0) {
		ll mn = min(s, k - 1);
		result[0] += mn;
		s -= mn;
	}

	if (s != 0) return {-1};

	return result;
}

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int testCases; cin >> testCases;
	while (testCases--) {
		auto result = solve();
		for (auto x : result) cout << x << ' ';
		cout << '\n';
	}
		
	return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1715/B