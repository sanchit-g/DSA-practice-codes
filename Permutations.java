import java.util.ArrayList;
import java.util.List;

public class Permutations {

	public static List<List<Integer>> permute(int[] nums) {

		List<List<Integer>> res = new ArrayList<>();
		recur(nums, new ArrayList<>(), new boolean[nums.length], res);
		return res;
	}

	private static void recur(int[] nums, List<Integer> subList, boolean[] used, List<List<Integer>> res) {

		if (subList.size() == nums.length) {
			res.add(new ArrayList<>(subList));
			return;
		}

		for (int i = 0; i < nums.length; i++) {
			// skipping used nums
			if (used[i])
				continue;

			// adding num to permutation, then marking it used
			subList.add(nums[i]);
			used[i] = true;

			// again calling the recur method on unused nums
			recur(nums, subList, used, res);

			// removing the last added num and marking it unused
			subList.remove(subList.size() - 1);
			used[i] = false;
		}
	}

	public static void main(String[] args) {

		int[] nums = new int[] { 1, 2, 3 };
		System.out.println(permute(nums));
	}
}
