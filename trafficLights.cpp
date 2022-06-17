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
    int x, n;
    cin >> x >> n;

    multiset<int> distances;
    set<int> lights;

    lights.insert(0);
    lights.insert(x);

    distances.insert(x);

    for (int i = 0; i < n; i++)
    {
        int pos;
        cin >> pos;

        auto it1 = lights.upper_bound(pos);
        auto it2 = it1;
        it2--;

        distances.erase(distances.find(*it1 - *it2));
        distances.insert(pos - *it2);
        distances.insert(*it1 - pos);
        lights.insert(pos);

        auto ans = distances.end();
        cout << *(--ans) << " ";
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
