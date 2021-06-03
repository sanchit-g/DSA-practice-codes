n = int(input())
dp = [1e9]*(n+1)
dp[0] = 0
for i in range(1, min(10, n+1)):
    dp[i] = 1
for i in range(10, n+1):
    s = str(i)
    for char in s:
        dp[i] = min(dp[i], 1 + dp[i-int(char)])
print(dp[n])
