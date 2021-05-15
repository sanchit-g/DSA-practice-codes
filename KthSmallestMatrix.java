
public class KthSmallestMatrix {

	public static int kthSmallest(int[][] matrix, int k) {

		int n = matrix.length;
		int start = matrix[0][0];
		int end = matrix[n - 1][n - 1];

		while (start < end) {
			int mid = start + (end - start) / 2;

			int[] smallLargePair = { matrix[0][0], matrix[n - 1][n - 1] };

			int count = countLessEqual(matrix, mid, smallLargePair);

			if (count == k) {
				return smallLargePair[0];
			}

			else if (count < k) {
				start = smallLargePair[1];
			}

			else {
				end = smallLargePair[0];
			}
		}

		return start;
	}

	private static int countLessEqual(int[][] matrix, int mid, int[] smallLargePair) {

		int count = 0;
		int n = matrix.length;
		int row = n - 1;
		int col = 0;

		while (row >= 0 && col < n) {
			if (matrix[row][col] > mid) {
				smallLargePair[1] = Math.min(smallLargePair[1], matrix[row][col]);
				row--;
			} else {
				smallLargePair[0] = Math.max(smallLargePair[0], matrix[row][col]);
				count += row + 1;
				col++;
			}
		}
		return count;
	}

	public static void main(String[] args) {

	}
}
