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
    bool ok[8][8];

    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
            ok[i][j] = (s[j] == '.');
    }

    vector<int> vals(8);

    // set vals to 0 1 2 ... 7
    iota(vals.begin(), vals.end(), 0);

    int ans = 0;

    do
    {
        bool works = true;
        bool blocked[16];

        for (int i = 0; i < 8; i++)
        {
            if (!ok[i][vals[i]])
                works = false;
        }

        memset(blocked, false, sizeof(blocked));

        // mark the diagonal from top left to bottom right
        for (int i = 0; i < 8; i++)
        {
            if (blocked[i + vals[i]])
                works = false;
            blocked[i + vals[i]] = true;
        }

        memset(blocked, false, sizeof(blocked));

        // mark the diagonal from top right to bottom left
        for (int i = 0; i < 8; i++)
        {
            if (blocked[i - vals[i] + 7])
                works = false;
            blocked[i - vals[i] + 7] = true;
        }

        if (works)
            ans++;

    } while (next_permutation(vals.begin(), vals.end()));

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
