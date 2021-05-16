import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class BTZigZagTraversal {

	public static List<List<Integer>> zigzagLevelOrder(TreeNode root) {

		List<List<Integer>> ans = new ArrayList<List<Integer>>();

		if (root == null)
			return ans;

		Stack<TreeNode> s1 = new Stack<>();
		Stack<TreeNode> s2 = new Stack<>();

		// Push the root
		s1.push(root);

		while (!s1.isEmpty() || !s2.isEmpty()) {
			List<Integer> level = new ArrayList<>();

			while (!s1.isEmpty()) {
				TreeNode temp = s1.pop();
				level.add(temp.val);

				if (temp.left != null)
					s2.push(temp.left);

				if (temp.right != null)
					s2.push(temp.right);
			}

			if (!level.isEmpty()) {
				ans.add(level);
			}

			level = new ArrayList<>();

			while (!s2.isEmpty()) {
				TreeNode temp = s2.pop();
				level.add(temp.val);

				if (temp.right != null)
					s1.push(temp.right);

				if (temp.left != null)
					s1.push(temp.left);
			}

			if (!level.isEmpty()) {
				ans.add(level);
			}
		}

		return ans;
	}

	public static void main(String[] args) {

	}
}
