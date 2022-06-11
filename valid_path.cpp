#include <bits/stdc++.h>

using namespace std;

#define MOD 10000003

// we can traverse in 8 directions.
int X[] = {0, 0, 1, 1, 1, -1, -1, -1};
int Y[] = {1, -1, 0, 1, -1, 0, 1, -1};

string solve(int x, int y, int N, int R, vector<int> &A, vector<int> &B)
{

    int rect[x + 1][y + 1];
    memset(rect, 0, sizeof(rect));

    for (int i = 0; i <= x; i++)
    {
        for (int j = 0; j <= y; j++)
        {
            for (int k = 0; k < N; k++)
            {
                // equation of circle - condition for a point to be on/inside of circle.
                if (pow(A[k] - i, 2) + pow(B[k] - j, 2) <= pow(R, 2))
                {
                    rect[i][j] = 1;
                    break;
                }
            }
        }
    }

    if (rect[0][0] == 1 or rect[x][y] == 1)
        return "NO";

    queue<pair<int, int>> q;

    q.push({0, 0});
    rect[0][0] = 1;

    while (!q.empty())
    {

        int a = q.front().first;
        int b = q.front().second;
        q.pop();

        if (a == x and b == y)
            return "YES";

        for (int i = 0; i < 8; i++)
        {

            int newA = a + X[i];
            int newB = b + Y[i];

            if (newA >= 0 and newA <= x and newB >= 0 and newB <= y and rect[newA][newB] != 1)
            {
                rect[newA][newB] = 1;
                q.push({newA, newB});
            }
        }
    }

    return "NO";
}

int main()
{
    int x = 2;
    int y = 3;
    int N = 1;
    int R = 1;
    vector<int> A{2};
    vector<int> B{3};

    cout << solve(x, y, N, R, A, B) << endl;

    return 0;
}
