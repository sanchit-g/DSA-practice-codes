#include <bits/stdc++.h>

using namespace std;

#define int                     long long
#define endl                    '\n'
#define pb                      emplace_back
#define mp                      make_pair
#define ff                      first
#define ss                      second
#define all(x)                  x.begin(), x.end()
#define rall(x)                 x.rbegin(), x.rend()
#define w(x)                    int x; cin>>x; while(x--)
#define setbits(x)              __builtin_popcountll(x)
#define zerobits(x)             __builtin_ctzll(x)
#define PI                      3.1415926535897932384626
#define mod                     1000000007
#define inf                     1000000000
typedef pair<int, int>          pi;
typedef vector<int>             vi;
typedef map<int, int>           mii;
typedef unordered_map<int, int> umii;
int gcd(int a, int b)   {if (a == 0) return b; return gcd(b % a, a);}
int lcm(int a, int b)   {return (a * b) / gcd(a, b);}
int mpow(int a, int b)  {
	int r = 1; a %= mod; for (; b; b >>= 1)
	{if (b & 1)r = r * a % mod; a = a * a % mod;} return r;
}
void fastIO()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

//<------------------------------------Code from here----------------------------------->//

vector<vector<int>> fourSum(vector<int>& nums, int k)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int rem, front, back, two_sum;
	vector<int> v;
	vector<vector<int>> res;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			rem = k - (nums[i] + nums[j]);
			front = j + 1;
			back = n - 1;
			while (front < back)
			{
				two_sum = nums[front] + nums[back];
				if (two_sum < rem)
					front++;
				else if (two_sum > rem)
					back--;
				else
				{
					v.push_back(nums[i]);
					v.push_back(nums[j]);
					v.push_back(nums[front]);
					v.push_back(nums[back]);
					res.push_back(v);

					while (front < back && nums[front] == v[2])
						front++;

					while (front < back && nums[back] == v[3])
						back--;

					v.clear();
				}
			}
			while (j + 1 < n && nums[j + 1] == nums[j])
				j++;
		}
		while (i + 1 < n && nums[i + 1] == nums[i])
			i++;
	}

	return res;
}


int32_t main()
{
	fastIO();
	vector<int> v{2, 3, 4, 5, 7, 8, 10};
	int k = 23;
	vector<vector<int>> ans = fourSum(v, k);
	for (auto v : ans)
		cout << v[0] << " " << v[1] << " " << v[2] << " " << v[3] << endl;

	return 0;
}