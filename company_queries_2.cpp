// Idea taken from Errichto's LCA video
// Video link : https://www.youtube.com/watch?v=dOAxrhAUIhA

#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;
const int LOG = 20;

vector<int> tree[N];
int up[N][LOG];
int depth[N];

void binary_lifting(int u, int parent = 0) {
	up[u][0] = parent;

	for (int i = 1; i < LOG; i++) {
		up[u][i] = up[up[u][i - 1]][i - 1];
	}

	for (auto v : tree[u]) {
		depth[v] = depth[u] + 1;
		binary_lifting(v, u);
	}
}

int ancestor(int x, int k) {
	for (int i = 0; i < LOG; i++) {
		if (k & (1 << i)) {
			x = up[x][i];
		}
	}
	return x;
}

int lca(int u, int v) {
	if (depth[u] < depth[v])
		swap(u, v);

	u = ancestor(u, depth[u] - depth[v]);

	if (u == v)
		return u;

	for (int i = LOG - 1; i >= 0; i--) {
		if (up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	}

	return up[u][0];
}

int32_t main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, q;
	cin >> n >> q;

	for (int i = 2; i <= n; i++) {
		int p;
		cin >> p;
		tree[p].push_back(i);
	}

	binary_lifting(1);

	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << lca(x, y) << '\n';
	}

	return 0;
}