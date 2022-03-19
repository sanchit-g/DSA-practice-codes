#include <bits/stdc++.h>

using namespace std;

#define int 	long long
#define endl 	"\n"
const int N = 100005;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int row, col;
	cin >> row >> col;

	int matrix[row][col];
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cin >> matrix[i][j];
	}

	int startingRow = 0;
	int endingRow = row - 1;
	int startingCol = 0;
	int endingCol = col - 1;

	int total = row * col;
	int count = 0;

	vector<int> ans;

	while (count < total)
	{
		// print starting row
		for (int i = startingCol; i <= endingCol && count < total; i++)
		{
			ans.push_back(matrix[startingRow][i]);
			count++;
		}
		startingRow++;

		// print ending column
		for (int i = startingRow; i <= endingRow && count < total; i++)
		{
			ans.push_back(matrix[i][endingCol]);
			count++;
		}
		endingCol--;

		// print ending row
		for (int i = endingCol; i >= startingCol && count < total; i--)
		{
			ans.push_back(matrix[endingRow][i]);
			count++;
		}
		endingRow--;

		// print starting column
		for (int i = endingRow; i >= startingRow && count < total; i--)
		{
			ans.push_back(matrix[i][startingCol]);
			count++;
		}
		startingCol++;
	}

	for (auto el : ans)
		cout << el << ", ";
	cout << "END" << endl;

	return 0;
}