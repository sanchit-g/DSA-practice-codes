#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e9 + 5
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl "\n"

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;

void solve()
{
    int t, a, b;
    cin >> t >> a >> b;

    vector<vector<bool>> dp(2, vector<bool>(t + 1, false));
    // dp[0][x] = true if we can attain x units of fullness without drinking water
    // dp[1][x] = true if we can attain x units of fullness after drinking water

    dp[0][0] = true;

    for (int i : {0, 1})
    {
        for (int j = 0; j <= t; j++)
        {
            if (!dp[i][j])
                continue;

            if (j + a <= t)
            {
                dp[i][j + a] = true;
            }

            if (j + b <= t)
            {
                dp[i][j + b] = true;
            }

            if (i == 0)
            {
                dp[1][j / 2] = true;
            }
        }
    }

    int res = t;

    // we need to find the maximum achievable fullness
    while (!dp[1][res])
    {
        res--;
    }

    cout << res << endl;
}

int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // USACO I/0 implementation
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    solve();
}
