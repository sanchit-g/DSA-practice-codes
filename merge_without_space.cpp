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

void solve(int nums1[], int n, int nums2[], int m)
{
	int i = 0, j = 0;

	while (i < n and j < m)
	{
		if (nums1[i] <= nums2[j])
			i++;

		else if (nums1[i] > nums2[j])
		{
			swap(nums1[i], nums2[j]);
			i++;
			// logic for insertion sorting
			for (int k = 1; k < m; k++)
			{
				int temp = nums2[k];
				int l = k - 1;

				while (l >= 0 and nums2[l] > temp)
				{
					nums2[l + 1] = nums2[l];
					l -= 1;
				}

				nums2[l + 1] = temp;
			}
		}
	}
}

int32_t main()
{
	fastIO();

	int n = 4;
	int nums1[n] = {1, 3, 5, 7};

	int m = 5;
	int nums2[m] = {0, 2, 6, 8, 9};

	solve(nums1, n, nums2, m);

	for (int i = 0; i < n; i++)
		cout << nums1[i] << " ";
	cout << endl;

	for (int i = 0; i < m; i++)
		cout << nums2[i] << " ";
	cout << endl;

	return 0;
}