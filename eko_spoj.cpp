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

bool isPossible(vector<int>& v, int n, int m, int mid)
{
	int cnt = 0;

	for (int i = 0; i < n; i++)
	{
		if (v[i] > mid)
			cnt += (v[i] - mid);
	}

	if (cnt >= m)
		return true;
	return false;
}

int solve(vector<int>& v, int n, int m)
{
	int low = 0, high = *max_element(v.begin(), v.end()), mid, res = -1;

	while (low <= high)
	{
		mid = low + (high - low) / 2;

		if (isPossible(v, n, m, mid))
		{
			res = mid;
			low = mid + 1;
		}

		else
			high = mid - 1;
	}

	return res;
}

int32_t main()
{
	fastIO();

	int n, m;
	cin >> n >> m;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	cout << solve(v, n, m) << endl;

	return 0;
}