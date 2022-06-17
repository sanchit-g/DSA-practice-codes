#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 2e9
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

    multiset<int> tickets;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        tickets.insert(x);
    }

    vector<int> customers(m);
    for (auto &x : customers)
        cin >> x;

    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        auto it = tickets.upper_bound(customers[i]);

        if (it == tickets.begin())
            res.push_back(-1);
        else
        {
            res.push_back(*(--it));
            tickets.erase(it);
        }
    }

    for (auto &x : res)
        cout << x << endl;
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
