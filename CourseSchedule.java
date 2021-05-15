import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Stack;

public class CourseSchedule {

	public static int[] findOrder(int numCourses, int[][] prerequisites) {
		int V = numCourses;

		// Constructing adjacency list
		List<Integer> graph[] = new ArrayList[V];
		for (int i = 0; i < V; i++) {
			graph[i] = new ArrayList<Integer>();
		}

		for (int i = 0; i < prerequisites.length; i++) {
			int[] pre = prerequisites[i];
			graph[pre[1]].add(pre[0]);
		}

		Stack<Integer> orderStack = new Stack<>();
		boolean[] visited = new boolean[V];
		boolean[] recStack = new boolean[V];

		for (int i = 0; i < V; i++) {
			if (!visited[i]) {
				if (!dfsUtil(i, graph, visited, recStack, orderStack)) {
					return new int[0];
				}
			}
		}

		int[] res = new int[V];
		for (int i = 0; i < V; i++) {
			res[i] = orderStack.pop();
		}

		return res;
	}

	private static boolean dfsUtil(int v, List<Integer> graph[], boolean[] visited, boolean[] recStack,
			Stack<Integer> orderStack) {

		if (recStack[v]) {
			// cycle detected
			return false;
		}

		if (visited[v]) {
			return true;
		}

		recStack[v] = true;
		visited[v] = true;

		Iterator<Integer> it = graph[v].iterator();
		while (it.hasNext()) {
			int n = it.next();
			if (!dfsUtil(n, graph, visited, recStack, orderStack)) {
				return false;
			}
		}

		recStack[v] = false;
		orderStack.push(v);
		return true;
	}

	public static void main(String[] args) {
		int numCourses = 4;
		int[][] prerequisites = new int[][] { { 1, 0 }, { 2, 0 }, { 3, 1 }, { 3, 2 } };

		int[] ans = findOrder(numCourses, prerequisites);
		for (int el : ans)
			System.out.print(el + " ");
	}
}
