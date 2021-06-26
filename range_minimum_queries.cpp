#include <bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int nums[N];
int segment_tree[4 * N];

void build(int index, int start, int end) {
	if (start == end) {
		segment_tree[index] = nums[end];
		return;
	}

	int mid = (start + end) / 2;

	build((2 * index) + 1, start, mid);
	build((2 * index) + 2, mid + 1, end);

	segment_tree[index] = min(segment_tree[(2 * index) + 1], segment_tree[(2 * index) + 2]);
}

void update(int index, int value, int curr_idx, int start, int end) {
	if (start == end) {
		segment_tree[curr_idx] = value;
		return;
	}

	int mid = (start + end) / 2;

	if (index <= mid) {
		update(index, value, (2 * curr_idx) + 1, start, mid);
	}
	else {
		update(index, value, (2 * curr_idx) + 2, mid + 1, end);
	}

	segment_tree[curr_idx] = min(segment_tree[(2 * curr_idx) + 1], segment_tree[(2 * curr_idx) + 2]);
}

int query(int l, int r, int curr_idx, int start, int end) {
	if (l <= start && r >= end) {
		return segment_tree[curr_idx];
	}

	if (l > end || r < start) {
		return INF;
	}

	int mid = (start + end) / 2;
	return min(query(l, r, (2 * curr_idx) + 1, start, mid), query(l, r, (2 * curr_idx) + 2, mid + 1, end));
}

int32_t main() {

	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, q;
	cin >> n >> q;

	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}

	build(0, 0, n - 1);

	while (q--) {
		int x, y;
		char query_type;

		cin >> query_type >> x >> y;

		if (query_type == 'q') {
			cout << query(x - 1, y - 1, 0, 0, n - 1) << '\n';
		} else {
			update(x - 1, y, 0, 0, n - 1);
		}
	}

	return 0;
}