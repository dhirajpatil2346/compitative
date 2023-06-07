def count_good_removals(A):
    N = len(A)
    dp = [0] * N
    even_count = 0
    mod = 10**9 + 7

    for i in range(N):
        if A[i] % 2 == 0:
            dp[i] = (dp[i-1] + even_count + 1) % mod
            even_count += 1
        else:
            dp[i] = dp[i-1]

    return dp[N-1]

# Example usage:
A = [1, 2, 3, 4]
result = count_good_removals(A)
print(result)