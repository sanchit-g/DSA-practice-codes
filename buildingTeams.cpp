#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define INF 1e9
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
 
const int N = 1e5 + 10;
 
int n, m;
vector<int> adj[N];
bool bad, visited[N], group[N];
 
void dfs(int node = 1, int color = 0)
{
    visited[node] = true;
    group[node] = color;
 
    for (int x : adj[node])
    {
        if (!visited[x])
            dfs(x, !color);
        else
        {
            if (group[x] == color)
                bad = true;
        }
    }
}
 
void solve()
{
    cin >> n >> m;
 
    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
 
    int i = 1;
    while (i <= n and !bad)
    {
        if (!visited[i])
            dfs(i);
        i++;
    }
 
    if (bad)
        cout << "IMPOSSIBLE" << endl;
 
    else
    {
        for (int i = 1; i <= n; i++)
            cout << group[i] + 1 << " ";
        cout << endl;
    }
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
