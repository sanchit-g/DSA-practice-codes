#include <bits/stdc++.h>

using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {

	deque<pair<int, int>> dq;   // deque contains pair (nums[index], index)
	vector<int> ans;    // stores max values of all sliding windows

	for (int i = 0; i < nums.size(); i++) {
		// pop the front element if it is out of window's range
		if (!dq.empty() and dq.front().second <= (i - k))
			dq.pop_front();
		// maintain the elements inside deque in descending order
		while (!dq.empty() and dq.back().first < nums[i])
			dq.pop_back();
		// push the curr element (along with its index) into the deque
		dq.push_back(make_pair(nums[i], i));
		// store the front val of deque if we have a valid window (of size k)
		if (i >= k - 1)
			ans.push_back(dq.front().first);
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