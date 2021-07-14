# for reference : https://bit.ly/2VBIuZn
# let dp[n] be the number of unique BSTs with n nodes
# we need to choose number of nodes in the left subtree
# and number of nodes in the right subtree
# for eg, if n = 5 then,
# f[5] = f[0]*f[4] + f[1]*f[3] + f[2]*f[2] + f[3]*f[1] + f[4]*f[0]

def main():
    def numTrees(n: int) -> int:
        dp = [0] * (n + 1)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            for j in range(i):
                dp[i] += dp[j] * dp[i - 1 - j]
        return dp[n]

    n = 5
    print(numTrees(n))


if __name__ == '__main__':
    main()
