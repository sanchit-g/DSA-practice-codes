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
    int n, m;
    cin >> n >> m;

    vector<int> nums(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nums[i];

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp[i][x] = number of valid arrays of size i where the ith element is x

    for (int i = 1; i <= n; i++)
    {
        for (int x = 1; x <= m; x++)
        {
            if (i == 1)
            {
                if (nums[i] == 0 or nums[i] == x)
                {
                    dp[i][x] = 1;
                }
            }

            else
            {
                if (nums[i] == 0 or nums[i] == x)
                {
                    dp[i][x] = dp[i - 1][x];

                    if (x - 1 > 0)
                    {
                        dp[i][x] += dp[i - 1][x - 1];
                        dp[i][x] %= MOD;
                    }

                    if (x + 1 <= m)
                    {
                        dp[i][x] += dp[i - 1][x + 1];
                        dp[i][x] %= MOD;
                    }
                }
            }
        }
    }

    // for (int i = 0; i < dp.size(); i++)
    // {
    //     for (int j = 0; j < dp[0].size(); j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }

    int ans = 0;
    for (int x = 1; x <= m; x++)
        ans = (ans + dp[n][x]) % MOD;

    cout << ans << endl;
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
    // freopen("feast.in", "r", stdin);
    // freopen("feast.out", "w", stdout);

    solve();
}
