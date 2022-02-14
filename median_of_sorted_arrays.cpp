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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{
	if (nums2.size() < nums1.size())
		return findMedianSortedArrays(nums2, nums1);

	int n1 = nums1.size();
	int n2 = nums2.size();

	int low = 0, high = n1;

	while (low <= high)
	{
		int cut1 = (low + high) >> 1;
		int cut2 = (n1 + n2 + 1) / 2 - cut1;

		int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
		int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

		int r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
		int r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

		if (l1 <= r2 and l2 <= r1)
		{
			if ((n1 + n2) % 2 == 0)
				return (max(l1, l2) + min(r1, r2)) / 2.0;
			else
				return max(l1, l2);
		}

		else if (l1 > r2)
			high = cut1 - 1;

		else
			low = cut1 + 1;
	}

	return 0.0;
}

int32_t main()
{
	fastIO();

	vector<int> nums1 {7, 12, 14, 15};
	vector<int> nums2 {1, 2, 3, 4, 9, 11};

	cout << findMedianSortedArrays(nums1, nums2) << endl;

	return 0;
}