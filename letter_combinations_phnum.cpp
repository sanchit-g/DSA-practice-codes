#include <bits/stdc++.h>

using namespace std;

#define int 	long long
#define endl 	"\n"
const int N = 100005;

void solve(string digits, vector<string>& ans, string output, int index, string mapping[])
{
	// base case
	if (index >= digits.length())
	{
		ans.push_back(output);
		return;
	}

	int number = digits[index] - '0';
	string val = mapping[number];

	for (int i = 0; i < val.length(); i++)
	{
		output.push_back(val[i]);
		solve(digits, ans, output, index + 1, mapping);
		output.pop_back();
	}
}

vector<string> letterCombinations(string digits) {

	vector<string> ans;
	if (digits.length() == 0)
		return ans;
	string output;
	int index = 0;
	string mapping[10] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

	solve(digits, ans, output, index, mapping);
	return ans;
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	string str;
	cin >> str;

	vector<string> res = letterCombinations(str);
	for (int i = 0; i < res.size(); i++)
		cout << res[i] << " ";
	cout << endl;
	cout << res.size() << endl;

	return 0;
}