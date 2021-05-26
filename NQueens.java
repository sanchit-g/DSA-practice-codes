import java.util.ArrayList;
import java.util.List;

public class NQueens {

	boolean[] visited;
	boolean[] diag;
	boolean[] antiDiag;
	List<List<String>> result = new ArrayList<>();

	public List<List<String>> solveNQueens(int n) {

		visited = new boolean[n];
		diag = new boolean[2 * n - 1];
		antiDiag = new boolean[2 * n - 1];

		// Initialise the board
		char[][] board = new char[n][n];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				board[i][j] = '.';
		}

		dfs(board, 0);

		return result;
	}

	private void dfs(char[][] board, int columnIndex) {

		int N = board.length;

		if (columnIndex == N) {
			result.add(construct(board));
			return;
		}

		for (int i = 0; i < N; i++) {
			if (isSafe(N, i, columnIndex)) {
				visited[i] = true;
				diag[i - columnIndex + N - 1] = true;
				antiDiag[i + columnIndex] = true;
				board[i][columnIndex] = 'Q';
				dfs(board, columnIndex + 1);
				board[i][columnIndex] = '.';
				visited[i] = false;
				diag[i - columnIndex + N - 1] = false;
				antiDiag[i + columnIndex] = false;
			}
		}
	}

	private boolean isSafe(int N, int i, int j) {
		return !visited[i] && !diag[i - j + N - 1] && !antiDiag[i + j];
	}

	private List<String> construct(char[][] board) {

		List<String> rowList = new ArrayList<>();

		for (int i = 0; i < board.length; i++) {
			String str = new String(board[i]);
			rowList.add(str);
		}

		return rowList;
	}
}
