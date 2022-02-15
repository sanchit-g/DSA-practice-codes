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

// Two pointers approach. Time complexity : O(k), Space complexity : O(1)
int solve(int nums1[], int nums2[], int n, int m, int k)
{
	int i = 0, j = 0;
	int count = 0;

	while (i < n and j < m)
	{
		if (nums1[i] < nums2[j])
		{
			count++;
			if (count == k)
				return nums1[i];
			i++;
		}

		else
		{
			count++;
			if (count == k)
				return nums2[j];
			j++;
		}
	}

	while (i < n)
	{
		count++;
		if (count == k)
			return nums1[i];
		i++;
	}

	while (j < m)
	{
		count++;
		if (count == k)
			return nums2[j];
		j++;
	}

	return 1;
}

// Binary search approach. Time complexity : O(log(min(n,m))), Space complexity : O(1)
int solve2(int nums1[], int nums2[], int n, int m, int k)
{
	if (n > m)
		return solve2(nums2, nums1, m, n, k);

	int low = max(0ll, k - m);
	int high = min(k, n);

	while (low <= high)
	{
		int cut1 = (high + low) >> 1;
		int cut2 = k - cut1;

		int l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
		int l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
		int r1 = cut1 == n ? INT_MAX : nums1[cut1];
		int r2 = cut1 == m ? INT_MAX : nums2[cut2];

		if (l1 <= r2 and l2 <= r1)
			return max(l1, l2);

		else if (l1 > r2)
			high = cut1 - 1;

		else
			low = cut1 + 1;
	}

	return 1;
}

int32_t main()
{
	fastIO();

	int n = 6;
	int m = 4;
	int k = 5;

	int nums1[n] = {1, 3, 4, 7, 10, 12};
	int nums2[m] = {2, 3, 6, 15};

	cout << solve2(nums1, nums2, n, m, k) << endl;

	return 0;
}