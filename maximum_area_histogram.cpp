#include <bits/stdc++.h>

using namespace std;

vector<int> NSR(vector<int>& A) {

	int n = A.size();
	stack<pair<int, int>> s;
	vector<int> res;

	for (int i = n - 1; i >= 0; i--)
	{
		while (!s.empty() and s.top().first >= A[i]) s.pop();
		if (s.empty()) res.push_back(n);
		else res.push_back(s.top().second);

		s.push({A[i], i});
	}

	reverse(res.begin(), res.end());
	return res;
}

vector<int> NSL(vector<int>& A) {

	int n = A.size();
	stack<pair<int, int>> s;
	vector<int> res;

	for (int i = 0; i < n; i++)
	{
		while (!s.empty() and s.top().first >= A[i]) s.pop();
		if (s.empty()) res.push_back(-1);
		else res.push_back(s.top().second);

		s.push({A[i], i});
	}

	return res;
}

int largestRectangleArea(vector<int>& heights) {

	int n = heights.size();

	vector<int> left = NSL(heights);
	vector<int> right = NSR(heights);

	vector<int> width(n);
	for (int i = 0; i < n; i++) width[i] = right[i] - left[i] - 1;

	vector<int> area(n);
	for (int i = 0; i < n; i++) area[i] = heights[i] * width[i];

	return *max_element(area.begin(), area.end());
}

int main(int argc, char const *argv[])
{
	vector<int> heights {2, 1, 5, 6, 2, 3};

	cout << largestRectangleArea(heights) << "\n";
	return 0;
}