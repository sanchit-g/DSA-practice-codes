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

bool isPossible(int n, int c, vector<int>& a, int dist)
{
	int cnt = 1, last_pos = a[0];

	for (int i = 1; i < n; i++)
	{
		if (a[i] - last_pos >= dist)
		{
			cnt++;
			last_pos = a[i];
		}

		if (cnt == c)
			return true;
	}

	return false;
}

int32_t main()
{
	fastIO();

	w(t)
	{
		int n, c;
		cin >> n >> c;

		vector<int> a(n);
		for (int i = 0; i < n; i++)
			cin >> a[i];

		sort(all(a));

		int low = 1, high = a[n - 1] - a[0], mid, res;

		while (low <= high)
		{
			mid = low + (high - low) / 2;

			if (isPossible(n, c, a, mid))
			{
				res = mid;
				low = mid + 1;
			}

			else
				high = mid - 1;
		}

		cout << res << endl;
	}

	return 0;
}