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
    int n, x;
    cin >> n >> x;
 
    vector<int> price(n);
    for (int &i : price)
        cin >> i;
 
    vector<int> pages(n);
    for (int &i : pages)
        cin >> i;
 
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= x; j++)
        {
            dp[i][j] = dp[i - 1][j];
 
            if (j - price[i - 1] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - price[i - 1]] + pages[i - 1]);
            }
        }
    }
 
    cout << dp[n][x] << endl;
}
 
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
}
