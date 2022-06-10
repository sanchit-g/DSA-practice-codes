#include <bits/stdc++.h>

using namespace std;

#define INF (int)1e9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl "\n"

typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef map<int, int> mii;
typedef unordered_map<int, int> umap_ii;
typedef unordered_map<string, int> umap_si;

int subCount(vl arr, ll n, ll k)
{
    vl mod(k, 0);
    ll cumSum = 0, rem;

    for (ll i = 0; i < n; i++)
    {
        cumSum += arr[i];
        rem = cumSum % k;
        if (rem < 0)
            rem += k;
        mod[rem]++;
    }

    ull res = 0;
    for (ll i = 0; i < k; i++)
    {
        if (mod[i] > 1)
            res += (mod[i] * (mod[i] - 1)) / 2;
    }
    // Suppose value of cumulative sum becomes 0 three times,
    // ...0....0....0....
    // Now let us name these indices as a, b and c.
    // ...a....b....c....
    // So in the for loop when you do mod[0]*(mod[0]-1)/2 = 3*2/2 = 3,
    // you count -> (a,b),(b,c) and (a,c).
    // But in case of mod = 0, you need to count (0,a), (0,b) and (0,c) also.
    // Hence, we are adding mod[0] at the end.
    res += mod[0];

    return res;
}

void solve()
{
    ll n;
    cin >> n;

    vl v(n);
    for (auto &x : v)
        cin >> x;

    cout << subCount(v, n, n) << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}