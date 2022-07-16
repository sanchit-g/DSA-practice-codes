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

const int N = 1000001;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> graph[n + 1];
    vector<int> indegree(n + 1, 0);

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;

        graph[a].push_back(b);
        indegree[b]++;
    }

    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    vector<int> order;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        order.push_back(curr);

        for (int &neighbor : graph[curr])
        {
            indegree[neighbor]--;

            if (indegree[neighbor] == 0)
                q.push(neighbor);
        }
    }

    if (order.size() != n)
    {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int &i : order)
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

    // USACO I/0 implementation
    // freopen("feast.in", "r", stdin);
    // freopen("feast.out", "w", stdout);

    solve();
}
