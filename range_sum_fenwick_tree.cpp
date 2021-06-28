#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int n, q;
int bit[N];

void update(int i, int val) {
	for (; i <= n; i += (i) & (-i)) {
		bit[i] += val;
	}
}

int sum(int i) {
	int ans = 0;
	for (; i; i -= (i) & (-i)) {
		ans += bit[i];
	}
	return ans;
}

int rsq(int l, int r) {
	return sum(r) - sum(l - 1);
}

int32_t main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		update(i, x);
	}

	while (q--) {
		int type;
		cin >> type;
		if (type == 1) {
			int k, u;
			cin >> k >> u;
			update(k, u - rsq(k, k));
		} else {
			int l, r;
			cin >> l >> r;
			cout << rsq(l, r) << '\n';
		}
	}
	return 0;
}