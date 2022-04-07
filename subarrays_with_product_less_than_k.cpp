#include <bits/stdc++.h>

using namespace std;

#define int 	long long
#define endl 	"\n"
const int N = 100005;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, k;
	cin >> n >> k;

	vector<int> nums(n);

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	// sliding window approach

	int prod = 1, count = 0, left = 0;

	for (int right = 0; right < n; right++) {

		prod *= nums[right];

		while (prod >= k) {
			prod /= nums[left];
			left++;
		}

		count += right - left + 1;
	}

	cout << count << endl;

	return 0;
}