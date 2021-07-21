#include <bits/stdc++.h>

using namespace std;

int lcs(string A, string B) {
	int n = A.size();
	int m = B.size();
	int dp[n + 1][m + 1];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (B[j - 1] == A[i - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}

int longestPalindromeSubseq(string s) {
	string t = s;
	reverse(t.begin(), t.end());
	return lcs(s, t);
}

int main(int argc, char const *argv[])
{
	string s = "jbbalcdeaj";
	cout << longestPalindromeSubseq(s) << endl;

	return 0;
}