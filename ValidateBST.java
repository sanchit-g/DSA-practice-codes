
public class ValidateBST {

	public static boolean isValidBST(TreeNode root) {

		if (helper(root, null, null))
			return true;

		return false;
	}

	private static boolean helper(TreeNode root, Integer mini, Integer maxi) {

		if (root == null)
			return true;

		if ((mini != null && root.val <= mini) || (maxi != null && root.val >= maxi))
			return false;

		boolean left_subtree = helper(root.left, mini, root.val);
		boolean right_subtree = helper(root.right, root.val, maxi);

		if (left_subtree && right_subtree)
			return true;
		else
			return false;
	}

	public static void main(String[] args) {

	}
}
