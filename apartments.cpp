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
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> applicants(n);
    for (int &x : applicants)
        cin >> x;

    vector<int> apartments(m);
    for (int &x : apartments)
        cin >> x;

    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0;
    int count = 0;

    while (i < n and j < m)
    {
        if (abs(applicants[i] - apartments[j]) > k)
        {
            if (applicants[i] > apartments[j])
                j++;
            else
                i++;
        }

        else
        {
            count++;
            i++;
            j++;
        }
    }

    cout << count << endl;
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
