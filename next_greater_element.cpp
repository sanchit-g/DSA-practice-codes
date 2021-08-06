#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

	stack<int> s;
	map<int, int> mp;

	int n = nums2.size();

	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() and s.top() < nums2[i])
			s.pop();

		if (s.empty())
			mp[nums2[i]] = -1;

		else
			mp[nums2[i]] = s.top();

		s.push(nums2[i]);
	}

	vector<int> ans;

	for (auto el : nums1)
		ans.push_back(mp[el]);

	return ans;
}

int main() {

	vector<int> nums1 {4, 1, 2};
	vector<int> nums2 {1, 3, 4, 2};

	vector<int> res = nextGreaterElement(nums1, nums2);

	for (auto el : res)
		cout << el << " ";
	cout << "\n";

	return 0;
}