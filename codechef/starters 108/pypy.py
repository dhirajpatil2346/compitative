def f(ind, mod, dp):
    if ind == 0:
        if mod == 0:
            return 1
        return 0

    if dp[ind][mod] != -1:
        return dp[ind][mod]

    ret = 0
    for i in range(10):
        ret += f(ind - 1, (mod + i) % 9, dp)

    dp[ind][mod] = ret
    return ret

def solve(dp):
    n = int(input())
    s = input().strip()
    opt = s.count('?')
    mod = sum(int(ch) for ch in s if ch != '?') % 9

    if opt == 0:
        if mod == 0:
            print(1)
        else:
            print(0)
        return

    ans = 0
    if s[0] == '?':
        for i in range(1, 10):
            ans += f(opt - 1, (mod + i) % 9, dp)
    else:
        ans = f(opt, mod, dp)

    print(ans)

if __name__ == "__main__":
    t = int(input())
    opt = 10**5 + 5
    dp = [[-1] * 10 for _ in range(opt)]

    # for i in range(opt):
    #     for mod in range(8, -1, -1):
    #         f(i, mod, dp)
    dp[0][0] = 1
    for i in range(1, opt, 1):
        for mod in range(9):
            for j in range(10):
                dp[i][mod]  = dp[i][mod] + dp[i-1][(mod+j)%9];
    for _ in range(t):
        solve(dp)
