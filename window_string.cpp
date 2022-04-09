#include <bits/stdc++.h>

using namespace std;

#define int 	long long
#define endl 	"\n"
const int N = 100005;

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string s, t;
	cin >> s >> t;

	int len1 = s.size();
	int len2 = t.size();

	if (len1 < len2)
		cout << "" << endl;

	unordered_map<char, int> mp;

	for (int i = 0; i < len2; i++)
		mp[t[i]]++;

	int count = mp.size();
	int i = 0, j = 0, min_len = INT_MAX, start_index = -1;

	while (j < len1) {
		if (mp.find(s[j]) != mp.end()) {
			mp[s[j]]--;
			if (mp[s[j]] == 0)
				count--;
		}

		if (count == 0) {
			while (i < len1) {
				if (mp.find(s[i]) == mp.end())
					i++;
				else if (mp[s[i]] < 0) {
					mp[s[i]]++;
					i++;
				}
				else if (mp[s[i]] == 0)
					break;
			}

			int size = j - i + 1;
			if (size < min_len) {
				min_len = size;
				start_index = i;
			}

			// move to the next window
			mp[s[i]]++;
			i++;
			count++;
		}
		j++;
	}

	string res = "";

	if (min_len != INT_MAX)
		res = s.substr(start_index, min_len);

	cout << res << endl;

	return 0;
}