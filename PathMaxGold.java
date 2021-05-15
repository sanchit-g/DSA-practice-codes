
public class PathMaxGold {

	private static final int[] dir = new int[] { 0, 1, 0, -1, 0 };

	public static int getMaximumGold(int[][] grid) {
		int m = grid.length;
		int n = grid[0].length;

		int ans = 0;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ans = Math.max(ans, dfs(grid, m, n, i, j));
			}
		}
		return ans;
	}

	private static int dfs(int[][] grid, int m, int n, int i, int j) {
		if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == 0)
			return 0;

		int origin = grid[i][j];
		grid[i][j] = 0; // mark as visited
		int sum = 0;

		for (int d = 0; d < 4; d++) {
			sum = Math.max(sum, dfs(grid, m, n, i + dir[d], j + dir[d + 1]));
		}

		grid[i][j] = origin; // restore original value;

		return sum + origin;
	}

	public static void main(String[] args) {

		int[][] grid = new int[][] { { 0, 6, 0 }, { 5, 8, 7 }, { 0, 9, 0 } };
		System.out.println(getMaximumGold(grid));
	}
}
