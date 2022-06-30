class Solution
{
public:
    int dp[101][10001];

    int solve(int e, int f)
    {
        // base case
        if (f == 0 or f == 1)
            return f;
        if (e == 1)
            return f;

        if (dp[e][f] != -1)
            return dp[e][f];

        int mn = INT_MAX;
        int l = 1, r = f;

        while (l <= r)
        {
            int mid = (l + r) / 2;

            if (dp[e - 1][mid - 1] == -1)
                dp[e - 1][mid - 1] = solve(e - 1, mid - 1);

            if (dp[e][f - mid] == -1)
                dp[e][f - mid] = solve(e, f - mid);

            int temp = 1 + max(dp[e - 1][mid - 1], dp[e][f - mid]);
            mn = min(mn, temp);

            // because our ultimate goal is to find the worst case scenario
            if (dp[e - 1][mid - 1] > dp[e][f - mid])
                r = mid - 1;
            else
                l = mid + 1;
        }

        return dp[e][f] = mn;
    }

    int superEggDrop(int k, int n)
    {
        memset(dp, -1, sizeof(dp));
        return solve(k, n);
    }
};
