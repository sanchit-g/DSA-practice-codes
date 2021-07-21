#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

	priority_queue<pair<int, int>> heap;    // heap contains pair (nums[index], index)
	vector<int> ans;    // stores max values of all sliding windows

	for (int i = 0; i < nums.size(); i++) {
		// pop the max element from heap if it is out of window's range
		while (!heap.empty() and heap.top().second <= (i - k))
			heap.pop();
		// push the curr element (along with its index) into the heap
		heap.push(make_pair(nums[i], i));
		// store the max val from heap if we have a valid window (of size k)
		if (i >= k - 1)
			ans.push_back(heap.top().first);
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	vector<int> nums {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;

	vector<int> res = maxSlidingWindow(nums, k);
	for (int el : res)
		cout << el << " ";
	cout << "\n";

	return 0;
}