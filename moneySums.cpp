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
    int n;
    cin >> n;
 
    vector<int> coins(n);
    for (int &c : coins)
        cin >> c;
 
    int max_possible_sum = n * 1000;
 
    vector<vector<bool>> dp(n + 1, vector<bool>(max_possible_sum + 1, false));
    
    // dp[i][x] = true, if it is possible to make a sum x using the first i coins.
 
    dp[0][0] = true;
 
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= max_possible_sum; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if ((j - coins[i - 1] >= 0) and dp[i - 1][j - coins[i - 1]])
            {
                dp[i][j] = true;
            }
        }
    }
 
    vector<int> possible_sums;
    for (int j = 1; j <= max_possible_sum; j++)
    {
        if (dp[n][j])
        {
            possible_sums.push_back(j);
        }
    }
 
    cout << possible_sums.size() << endl;
    for (int &i : possible_sums)
        cout << i << " ";
    cout << endl;
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
