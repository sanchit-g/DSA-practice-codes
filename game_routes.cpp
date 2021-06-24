#include <bits/stdc++.h>

using namespace std;

#define int long long
#define N 100005
#define MOD 1000000007

vector<int> a[N];
bool visited[N];
stack<int> st;

void dfs(int node) {
	visited[node] = 1;
	for (auto i : a[node]) {
		if (!visited[i])
			dfs(i);
	}
	st.push(node);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;

	int x, y;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		a[x].push_back(y);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i);
	}

	vector<int> ordering;

	while (!st.empty()) {
		ordering.push_back(st.top());
		st.pop();
	}

	vector<int> dp(n + 1, 0);
	dp[1] = 1;

	for (auto i : ordering) {
		if (dp[i] != 0) {
			for (auto j : a[i]) {
				dp[j] += dp[i];
				dp[j] %= MOD;
			}
		}
	}

	cout << dp[n] << '\n';

	return 0;
}
