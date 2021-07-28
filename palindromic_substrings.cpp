#include <bits/stdc++.h>

using namespace std;

int countSubstrings(string s) {

	int n = s.length();

	bool dp[n + 1][n + 1];
	memset(dp, false, sizeof(dp));

	int count = 0;

	// every isolated char is a palindrome
	for (int i = 0; i < n; i++) {
		dp[i][i] = true;
		count++;
	}

	// substrings of size 2
	for (int i = 0; i < n - 1; i++) {
		if (s[i] == s[i + 1]) {
			dp[i][i + 1] = true;
			count++;
		}
	}

	// substrings of size 3 or more
	for (int k = 3; k <= n; k++) {
		for (int i = 0; i <= n - k; i++) {
			int j = i + k - 1;
			if (s[i] == s[j] and dp[i + 1][j - 1]) {
				dp[i][j] = true;
				count++;
			}
		}
	}

	return count;
}

int main() {

	string s = "aabaa";
	cout << countSubstrings(s) << "\n";

	return 0;
}