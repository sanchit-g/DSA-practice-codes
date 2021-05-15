import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;
import java.util.Set;

class TreeNode {
	int val;
	TreeNode left;
	TreeNode right;

	TreeNode(int x) {
		val = x;
	}
}

public class DistanceKBinaryTree {

	public static List<Integer> distanceK(TreeNode root, TreeNode target, int k) {
		Map<TreeNode, TreeNode> parent = new HashMap<>();
		Queue<TreeNode> queue = new LinkedList<>();

		dfs(root, null, parent);

		Set<TreeNode> visited = new HashSet<>();

		queue.add(target);
		visited.add(target);

		int level = 0;

		// Typical BFS
		while (!queue.isEmpty()) {
			if (level == k)
				break;
			int size = queue.size();
			for (int i = 0; i < size; i++) {
				TreeNode node = queue.poll();

				if (node.left != null && !visited.contains(node.left)) {
					visited.add(node.left);
					queue.offer(node.left);
				}

				if (node.right != null && !visited.contains(node.right)) {
					visited.add(node.right);
					queue.offer(node.right);
				}

				TreeNode par = parent.get(node);

				if (par != null && !visited.contains(par)) {
					visited.add(par);
					queue.offer(par);
				}
			}

			level++;
		}

		List<Integer> res = new ArrayList<>();
		for (TreeNode i : queue) {
			res.add(i.val);
		}

		return res;
	}

	private static void dfs(TreeNode node, TreeNode par, Map<TreeNode, TreeNode> parent) {
		if (node == null)
			return;

		parent.put(node, par);
		dfs(node.left, node, parent);
		dfs(node.right, node, parent);
	}

	public static void main(String[] args) {

	}
}
