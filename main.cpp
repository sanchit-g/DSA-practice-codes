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

void solve(ll test_case)
{
    int n;
    cin >> n;

    vi gas, cost;
    
    int x, totalGas = 0, totalCost = 0;
    for(int i = 0; i < n; i++) {
        cin >> x;
        gas.push_back(x);
        totalGas += x;
    }

    for(int i = 0; i < n; i++) {
        cin >> x;
        cost.push_back(x);
        totalCost += x;
    }

    if(totalGas < totalCost)
    {
        cout << "-1" << endl;
        return;
    }

    int start = 0, fuel = 0;
    for(int i = 0; i < n; i++) {
        fuel += gas[i];
        if(fuel >= cost[i]) {
            // can go further
            fuel -= cost[i];
        }
        else {
            fuel = 0;
            start = (i + 1) % n;
        }
    }

    cout << start << endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t, t1 = 0;
    cin >> t;
    while (t1 < t)
    {
        solve(t1 + 1);
        t1++;
    }
}