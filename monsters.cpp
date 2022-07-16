#include <bits/stdc++.h>

using namespace std;

#define int long long
#define INF 1e9 + 7
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

const int N = 1001;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
char dir[4] = {'R', 'D', 'L', 'U'};

void solve()
{
    int n, m;
    cin >> n >> m;

    char grid[n + 1][m + 1];
    vector<pair<int, int>> monsters;
    pair<int, int> start;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                start = make_pair(i, j);

            else if (grid[i][j] == 'M')
                monsters.push_back(make_pair(i, j));
        }
    }

    queue<pair<int, int>> q;
    bool visited[n + 1][m + 1];
    int dist[n + 1][m + 1];

    memset(visited, false, sizeof(visited));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            dist[i][j] = INF;

    for (auto &p : monsters)
    {
        q.push(p);
        dist[p.first][p.second] = 0;
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 1 and new_x <= n and new_y >= 1 and new_y <= m and grid[new_x][new_y] == '.' and !visited[new_x][new_y])
            {
                visited[new_x][new_y] = true;
                dist[new_x][new_y] = dist[x][y] + 1;
                q.push(make_pair(new_x, new_y));
            }
        }
    }

    memset(visited, false, sizeof(visited));

    int par[n + 1][m + 1];
    memset(par, 0, sizeof(par));

    bool possible[n + 1][m + 1];
    memset(possible, false, sizeof(possible));

    q.push(start);
    par[start.first][start.second] = -1;
    dist[start.first][start.second] = 0;
    possible[start.first][start.second] = true;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int new_x = x + dx[i];
            int new_y = y + dy[i];

            if (new_x >= 1 and new_x <= n and new_y >= 1 and new_y <= m and grid[new_x][new_y] == '.' and !visited[new_x][new_y])
            {
                visited[new_x][new_y] = true;

                int d = dist[x][y] + 1;
                if (d < dist[new_x][new_y])
                {
                    possible[new_x][new_y] = true;
                    dist[new_x][new_y] = d;
                }

                par[new_x][new_y] = i;
                q.push(make_pair(new_x, new_y));
            }
        }
    }

    bool flag = false;
    pair<int, int> end;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 or j == 1 or i == n or j == m)
            {
                if (possible[i][j])
                {
                    end = make_pair(i, j);
                    flag = true;
                    break;
                }
            }
        }
    }

    if (!flag)
    {
        cout << "NO" << endl;
        return;
    }

    string path = "";
    while (par[end.first][end.second] != -1)
    {
        int d = par[end.first][end.second];
        path += dir[d];
        end.first -= dx[d];
        end.second -= dy[d];
    }

    reverse(path.begin(), path.end());

    cout << "YES" << endl;
    cout << path.size() << endl;
    cout << path << endl;
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
