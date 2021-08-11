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

int maximalRectangle(vector<vector<char>>& matrix) {

	if (matrix.empty()) return 0;

	int n = matrix.size();
	int m = matrix[0].size();
	vector<int> v;

	for (int j = 0; j < m; j++)
	{
		if (matrix[0][j] == '0') v.push_back(0);
		else v.push_back(1);
	}

	int mx = largestRectangleArea(v);

	for (int i = 1; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (matrix[i][j] == '0') v[j] = 0;
			else v[j] += 1;
		}
		mx = max(mx, largestRectangleArea(v));
	}

	return mx;
}

int main(int argc, char const *argv[])
{
	vector<vector<char>> matrix {{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}};

	cout << maximalRectangle(matrix) << "\n";
	return 0;
}