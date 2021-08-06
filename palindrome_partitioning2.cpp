#include <bits/stdc++.h>

using namespace std;

#define int 	long long
#define endl	'\n'

int dp[2001][2001];
int dp2[2001][2001];

bool isPalindrome(string& s, int i, int j) {

	if (i >= j)
		return true;

	if (dp2[i][j] != -1)
		return dp2[i][j];

	if (s[i] == s[j])
		return dp2[i][j] = isPalindrome(s, i + 1, j - 1);

	return dp2[i][j] = false;
}

int solve(string& s, int i, int j) {

	if (i == j or isPalindrome(s, i, j))
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];

	int mn = INT_MAX;

	for (int k = i; k <= j - 1; k++)
	{
		if (isPalindrome(s, i, k)) {
			int temp = solve(s, k + 1, j) + 1;
			mn = min(mn, temp);
		}
	}

	return dp[i][j] = mn;
}

int minCut(string s) {

	int n = s.size();
	memset(dp, -1, sizeof(dp));
	memset(dp2, -1, sizeof(dp2));

	return solve(s, 0, n - 1);
}

int32_t main() {

	string str = "ababbbabbababa";

	cout << minCut(str) << endl;
	return 0;
}