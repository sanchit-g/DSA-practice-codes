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
    int N, M;
    cin >> N >> M;

    vector<vector<int>> adj(N + 1);
    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> dist(N + 1, INT_MAX);
    vector<int> parent(N + 1);

    queue<int> q;

    dist[1] = 1;
    q.push(1);

    while (!q.empty())
    {
        int x = q.front();
        q.pop();

        for (int &neighbor : adj[x])
        {
            if (dist[neighbor] == INT_MAX)
            {
                dist[neighbor] = dist[x] + 1;
                parent[neighbor] = x;
                q.push(neighbor);
            }
        }
    }

    if (dist[N] == INT_MAX)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    cout << dist[N] << endl;

    vector<int> v{N};
    while (v.back() != 1)
        v.push_back(parent[v.back()]);
    reverse(v.begin(), v.end());

    for (int &i : v)
        cout << i << " ";
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
