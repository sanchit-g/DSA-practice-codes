#include <bits/stdc++.h>

using namespace std;

bool isGoodSubstring(vector<int> count) {
	return (count[0] >= 1 and count[1] >= 1 and count[2] >= 1);
}

int numberOfSubstrings(string s) {

	int n = s.size();
	int i = 0, j = 0, ans = 0;
	vector<int> count(3, 0);

	while (j < n) {

		count[s[j] - 'a']++;

		if (!isGoodSubstring(count))
			j++;
		else {
			// Consider a good substring is found in the range [i ... j]. Now all the
			// substrings like [i ... j+1] ... ...[i ... N] will also be a good substring.
			// Hence we need to count all of them. ans += (n - j) takes care of this.
			while (isGoodSubstring(count)) {
				ans += (n - j);
				count[s[i] - 'a']--;
				i++;
			}
			j++;
		}
	}

	return ans;
}

int main(int argc, char const *argv[])
{
	string s = "abcabc";

	cout << numberOfSubstrings(s) << "\n";
	return 0;
}