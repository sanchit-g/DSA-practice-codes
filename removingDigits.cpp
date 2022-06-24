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
 
// vector<int> dp(1000001);
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> dp(n + 2, INF);
    dp[0] = 0;
 
    for (int i = 1; i <= n + 1; i++)
    {
        unordered_set<int> s;
        for (char j : to_string(i))
        {
            s.insert(j - '0');
        }
 
        for (int j : s)
        {
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
 
    cout << dp[n] << endl;
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
