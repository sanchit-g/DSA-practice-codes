#include <bits/stdc++.h>

using namespace std;

#define int 	long long
#define endl 	"\n"
const int N = 100005;

int f(int i, int j1, int j2, int n, int m, vector<vector<int>> &grid, vector<vector<vector<int>>>& dp) {

	// out of bounds
	if (j1 < 0 or j2 < 0 or j1 >= m or j2 >= m)
		return -1e9;

	if (i == n - 1) {
		if (j1 == j2) return grid[i][j1];
		else return grid[i][j1] + grid[i][j2];
	}

	if (dp[i][j1][j2] != -1)
		return dp[i][j1][j2];

	int maxi = INT_MIN;

	for (int di = -1; di <= 1; di++) {
		for (int dj = -1; dj <= 1; dj++) {
			int value;
			if (j1 == j2)
				value = grid[i][j1] + f(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
			else
				value = grid[i][j1] + grid[i][j2] + f(i + 1, j1 + di, j2 + dj, n, m, grid, dp);
			maxi = max(maxi, value);
		}
	}

	return dp[i][j1][j2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) {

	// int dp[r][c][c]
	vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
	return f(0, 0, c - 1, r, c, grid, dp);
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	vector<vector<int>> matrix {
		{2, 3, 1, 2},
		{3, 4, 2, 2},
		{5, 6, 3, 5},
	};

	int n = matrix.size();
	int m = matrix[0].size();

	cout << maximumChocolates(n, m, matrix);

	return 0;
}