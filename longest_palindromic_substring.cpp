#include <bits/stdc++.h>

using namespace std;

string longestPalindrome(string s) {
	int n = s.length();

	bool dp[n + 1][n + 1];
	memset(dp, false, sizeof(dp));

	// every isolated char is a palindrome
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
	}

	int start_index = 0;
	int max_len = 1;

	// substrings of size 2
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
			start_index = i;
			max_len = 2;
		}
	}

	// substrings of size 3 or more
	for (int k = 3; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			int j = i + k - 1;
			if (s[i] == s[j] and dp[i + 1][j - 1]) {
				dp[i][j] = true;
				if (k > max_len) {
					start_index = i;
					max_len = k;
				}
			}
		}
	}

	return s.substr(start_index, max_len);
}

int main(int argc, char const *argv[])
{
	string s = "cbbd";
	cout << longestPalindrome(s) << "\n";

	return 0;
}