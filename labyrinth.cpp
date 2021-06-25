#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '/n'

const int N = 1e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
char d[4] = {'R', 'D', 'L', 'U'};

int n, m;
char grid[N][N];
queue<pair<int, int>> q;
int pre[N][N];

bool isValid(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == '.';
}

bool isDestination(int i, int j) {
	return 0 <= i && i < n && 0 <= j && j < m && grid[i][j] == 'B';
}

void bfs(int i, int j) {
	q.push({i, j});

	while (q.size()) {
		auto [x, y] = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int new_x = x + dx[k];
			int new_y = y + dy[k];

			if (isDestination(new_x, new_y)) {
				pre[new_x][new_y] = k;

				string ans;
				while (grid[new_x][new_y] != 'A') {
					int p = pre[new_x][new_y];
					new_x -= dx[p];
					new_y -= dy[p];
					ans += d[p];
				}

				reverse(ans.begin(), ans.end());

				cout << "YES\n" << ans.size() << '\n' << ans << '\n';
			}

			else if (isValid(new_x, new_y)) {
				grid[new_x][new_y] = '*';
				q.push({new_x, new_y});
				pre[new_x][new_y] = k;
			}
		}
	}

	cout << "NO\n" << endl;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int x_A, y_A;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'A') {
				x_A = i, y_A = j;
			}
		}
	}

	bfs(x_A, y_A);

	return 0;
}
