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

void solve()
{
    int n;
    cin >> n;

    vector<pair<int, int>> vals;

    for (int i = 0; i < n; i++)
    {
        int l, r;
        cin >> l >> r;
        vals.push_back({l, 1});
        vals.push_back({r, -1});
    }

    sort(vals.begin(), vals.end());

    int sum = 0, ans = -INF;
    for (auto x : vals)
    {
        sum += x.second;
        ans = max(ans, sum);
    }

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

    solve();
}
