import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Stack;

public class NextLargerNode {

	public static int[] nextLargerNodes(ListNode head) {

		List<Integer> a = new ArrayList<>();

		for (ListNode node = head; node != null; node = node.next) {
			a.add(node.val);
		}

		int n = a.size();

		List<Integer> ans = new ArrayList<>();
		Stack<Integer> s = new Stack<>();

		for (int i = n - 1; i >= 0; i--) {
			while (!s.isEmpty() && s.peek() <= a.get(i)) {
				s.pop();
			}

			if (s.isEmpty()) {
				ans.add(0);
			} else {
				ans.add(s.peek());
			}

			s.push(a.get(i));
		}

		Collections.reverse(ans);

		int[] res = new int[ans.size()];
		for (int i = 0; i < ans.size(); i++) {
			res[i] = ans.get(i);
		}

		return res;
	}

	public static void main(String[] args) {

	}
}
