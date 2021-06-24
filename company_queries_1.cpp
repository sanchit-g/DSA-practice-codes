#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int LOG = 20;

vector<int> tree[N];
int up[N][LOG];

// up[v][j] = 2^jth ancestor of v

void binary_lifting(int u, int parent = 0) {
	up[u][0] = parent;

	for (int i = 1; i < LOG; i++) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}

	for (auto v : tree[u]) {
		binary_lifting(v, u);
	}
}

int ancestor(int x, int k) {
	for (int i = 0; i < LOG; i++) {
		if (k & (1 << i)) {
			x = up[x][i];
		}
	}
	return x ? x : -1;
}

int32_t main() {

	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		tree[p].push_back(i);
	}

	binary_lifting(1);

	while (q--) {
		int x, k;
		cin >> x >> k;
		cout << ancestor(x, k) << '\n';
	}

	return 0;
}