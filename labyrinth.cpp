#include <bits/stdc++.h>

using namespace std;

#define int 	long long
#define endl	'/n'

int n, m;
char grid[1002][1002];
queue<pair<int, int>> q;
bool visited[1002][1002];
map<pair<int, int>, pair<int, int>> parent;

void bfs(int x, int y) {
	q.push({x, y});
	visited[x][y] = 1;

	while (q.size()) {
		pair<int, int> temp = q.front();
		q.pop();

		x = temp.first;
		y = temp.second;

		if (grid[x][y] == 'B') {
			break;
		}

		if (x)
		{
			if (!visited[x - 1][y] and grid[x - 1][y] != '#')
			{
				parent[ {x - 1, y}] = {x, y};
				q.push({x - 1, y});
			}

			visited[x - 1][y] = 1;
		}

		if (y)
		{
			if (!visited[x][y - 1] and grid[x][y - 1] != '#')
			{
				parent[ {x, y - 1}] = {x, y};
				q.push({x, y - 1});
			}

			visited[x][y - 1] = 1;
		}

		if (x < n - 1)
		{
			if (!visited[x + 1][y] and grid[x + 1][y] != '#')
			{
				parent[ {x + 1, y}] = {x, y};
				q.push({x + 1, y});
			}

			visited[x + 1][y] = 1;
		}

		if (y < m - 1)
		{
			if (!visited[x][y + 1] and grid[x][y + 1] != '#')
			{
				parent[ {x, y + 1}] = {x, y};
				q.push({x, y + 1});
			}

			visited[x][y + 1] = 1;
		}
	}
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	int x, y, a, b;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 'A') {
				x = i, y = j;
			}
			else if (grid[i][j] == 'B') {
				a = i, b = j;
			}
		}
	}

	bfs(x, y);

	if (visited[a][b]) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}

	if (visited[a][b]) {
		vector<pair<int, int>> path;
		while (1) {
			path.push_back({a, b});

			if (a == x && b == y) {
				break;
			}

			int temp_a = a, temp_b = b;
			a = parent[ {temp_a, temp_b}].first;
			b = parent[ {temp_a, temp_b}].second;
		}

		reverse(path.begin(), path.end());

		string s;
		for (int i = 0; i < path.size() - 1; i++) {

			if (path[i].first == path[i + 1].first && path[i].second < path[i + 1].second)
				s += 'R';
			if (path[i].first == path[i + 1].first && path[i].second > path[i + 1].second)
				s += 'L';
			if (path[i].first < path[i + 1].first && path[i].second == path[i + 1].second)
				s += 'D';
			if (path[i].first > path[i + 1].first && path[i].second == path[i + 1].second)
				s += 'U';

		}

		cout << s.length() << '\n' << s;
	}
	return 0;
}