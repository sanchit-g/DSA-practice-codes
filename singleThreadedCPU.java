import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;

public class singleThreadedCPU {

	public static int[] getOrder(int[][] tasks) {
		int n = tasks.length;

		ArrayList<int[]> taskLists = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			taskLists.add(new int[] { tasks[i][0], tasks[i][1], i });
		}

		Collections.sort(taskLists, (a, b) -> a[0] - b[0]);

		PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> a[1] == b[1] ? a[2] - b[2] : a[1] - b[1]);

		int[] order = new int[n];

		int time = 0, index = 0, indexToAns = 0;

		while (index < n || !minHeap.isEmpty()) {

			if (minHeap.isEmpty()) {
				time = Math.max(taskLists.get(index)[0], time);
			}

			while (index < n && taskLists.get(index)[0] <= time) {
				minHeap.offer(taskLists.get(index));
				index++;
			}

			int[] topmost = minHeap.poll();

			order[indexToAns] = topmost[2];
			indexToAns++;

			time += topmost[1];
		}

		return order;
	}

	public static void main(String[] args) {

		int[][] tasks = new int[][] { { 1, 2 }, { 2, 4 }, { 3, 2 }, { 4, 1 } };

		int[] res = getOrder(tasks);
		for (int el : res) {
			System.out.print(el + " ");
		}
	}
}
