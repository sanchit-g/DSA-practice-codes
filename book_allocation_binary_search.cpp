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

bool isPossible(int barrier, vector<int>& a, int m, int n)
{
	int cnt = 1, pages = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] > barrier)
			return false;

		else if (pages + a[i] > barrier)
		{
			cnt++;
			pages = a[i];
		}

		else
			pages += a[i];
	}

	if (cnt > m)
		return false;
	return true;
}

int bookAllocation(int n, vector<int>& a, int m)
{
	int low = a[0], high = 0;
	for (int i = 0; i < n; i++)
	{
		high += a[i];
		low = min(low, a[i]);
	}

	int mid, ans = -1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;

		if (isPossible(mid, a, m, n))
		{
			ans = mid;
			high = mid - 1;
		}

		else
			low = mid + 1;
	}

	return ans;
}

int32_t main()
{
	fastIO();

	int N = 4;
	vector<int> A {12, 34, 67, 90};
	int M = 2;

	cout << bookAllocation(N, A, M) << endl;

	return 0;
}