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
 
vector<int> dp(1000001);
 
void solve()
{
    int n, x;
    cin >> n >> x;
 
    vector<int> coins(n);
    for (int &c : coins)
        cin >> c;
 
    dp[0] = 1;
 
    for (int c : coins)
    {
        for (int i = 1; i <= x; i++)
        {
            if (i - c >= 0)
            {
                dp[i] = dp[i] + dp[i - c];
                dp[i] %= MOD;
            }
        }
    }
 
    cout << dp[x] << endl;
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
