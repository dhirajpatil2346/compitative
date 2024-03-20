def findLongestSequence(s, k):
    n = len(s)
    zeros = [0] * n

    for i in range(n):
        if s[i] == '0':
            zeros[i] = 1

    for i in range(1, len(zeros)):
        zeros[i] += zeros[i - 1]

    mx = 1
    for i in range(n):
        pos = zeros.index(zeros[i] - k) if (zeros[i] - k) in zeros else -1

        if zeros[i] <= k:
            mx = max(mx, i - pos + 1)
        else:
            mx = max(mx, i - pos)

    x = 0
    for i in range(mx - 1, n):
        r = zeros[i]
        f = zeros[i - mx] if (i - mx) >= 0 else 0

        if (r - f) <= k:
            x += 1

    return x

s = input()
k = int(input())
result = findLongestSequence(s, k)
print(result)