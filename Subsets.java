import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

public class Subsets {
//	static List<List<Integer>> res = new ArrayList<>();
//
//	public static List<List<Integer>> subsets(int[] nums) {
//		dfs(new LinkedList<Integer>(), 0, nums);
//		return res;
//	}
//
//	private static void dfs(List<Integer> subList, int idx, int[] nums) {
//		if (idx > nums.length)
//			return;
//
//		res.add(new LinkedList<Integer>(subList));
//
//		for (int i = idx; i < nums.length; i++) {
//			subList.add(nums[i]);
//			dfs(subList, i + 1, nums);
//			subList.remove(subList.size() - 1);
//		}
//	}

	static List<List<Integer>> res = new ArrayList<>();

	public static List<List<Integer>> subsets(int[] nums) {

		recur(nums, new Stack<Integer>(), 0);
		return res;
	}

	private static void recur(int[] nums, Stack<Integer> subList, int start) {
		if (start == nums.length) {
			res.add(new ArrayList<>(subList));
			return;
		}

		// include nums[start]
		subList.push(nums[start]);
		recur(nums, subList, start + 1);

		subList.pop();

		// don't include nums[start]
		recur(nums, subList, start + 1);
	}

	public static void main(String[] args) {

		int[] nums = new int[] { 1, 2, 3 };
		System.out.println(subsets(nums));
	}
}
