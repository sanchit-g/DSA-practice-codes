#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

int solve(vector<int>& height) {

	int n = height.size();
	int i = 0, j = n - 1;
	int ans = -1;
	while (i < j) {
		ans = max(ans, (j - i) * min(height[i], height[j]));
		if (height[i] < height[j])
			i++;
		else
			j--;
	}

	return ans;
}

int main() {

	vector<int> height {4, 3, 2, 1, 4};
	cout << solve(height) << endl;

	return 0;
}