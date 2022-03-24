#include <bits/stdc++.h>

using namespace std;

#define int 	long long
#define endl 	"\n"
const int N = 1005;

bool visited[N][N];
int soln[N][N];

bool solve(char maze[][N], int n, int m, int i, int j)
{
	// base case
	if (i == n and j == m)
	{
		soln[i][j] = 1;
		for (int x = 1; x <= n; x++)
		{
			for (int y = 1; y <= m; y++)
				cout << soln[x][y] << " ";
			cout << endl;
		}
		return true;
	}

	if (visited[i][j])
		return false;

	visited[i][j] = 1;
	soln[i][j] = 1;

	if (j + 1 <= m and !visited[i][j + 1] and maze[i][j + 1] != 'X')
	{
		bool right_ans = solve(maze, n, m, i, j + 1);
		if (right_ans)
			return true;
	}

	if (i + 1 <= n and !visited[i + 1][j] and maze[i + 1][j] != 'X')
	{
		bool down_ans = solve(maze, n, m, i + 1, j);
		if (down_ans)
			return true;
	}

	soln[i][j] = 0;

	return false;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;

	char maze[N][N];

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			cin >> maze[i][j];
	}

	bool isPossible = solve(maze, n, m, 1, 1);

	if (!isPossible)
		cout << "-1" << endl;

	return 0;
}