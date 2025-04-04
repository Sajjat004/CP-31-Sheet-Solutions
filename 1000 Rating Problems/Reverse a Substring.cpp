#include <bits/stdc++.h>
using namespace std;

int32_t main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n;
	string s; cin >> s;

	int minCharIndex = n - 1;

	for (int i = n - 2; i >= 0; --i) {
		if (s[i] > s[minCharIndex]) {
			cout << "YES" << '\n';
			cout << i + 1 << ' ' << minCharIndex + 1 << '\n';
			return 0;
		}
		if (s[i] < s[minCharIndex]) {
			minCharIndex = i;
		}
	}

	cout << "NO" << '\n';
		
	return 0;
}

// Problem Link: https://codeforces.com/problemset/problem/1155/A