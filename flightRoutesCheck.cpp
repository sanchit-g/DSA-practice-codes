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
vector<int> adj1[N], adj2[N];
bool visited[N];

void DFS1(int x)
{
    visited[x] = true;
    for (int y : adj1[x])
    {
        if (!visited[y])
            DFS1(y);
    }
}

void DFS2(int x)
{
    visited[x] = true;
    for (int y : adj2[x])
    {
        if (!visited[y])
            DFS2(y);
    }
}

void solve()
{
    cin >> n >> m;

    int u, v;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        u--, v--;
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));

    // check if we can get from node 1 to all other nodes
    DFS1(0);

    // check if any of the nodes is not visited
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl;
            cout << 1 << " " << i + 1 << endl;
            return;
        }
    }

    // check if we can reach 1 from all other nodes
    memset(visited, false, sizeof(visited));

    DFS2(0);

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            cout << "NO" << endl;
            cout << i + 1 << " " << 1 << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
