def findLongestSequence(s, k):
    n = len(s)
    zeros = [0] * n

    for i in range(n):
        if s[i] == '0':
            zeros[i] = 1

    for i in range(1, len(zeros)):
        zeros[i] += zeros[i - 1]
    position = [n] * (n+1)
    for i in range(len(zeros)):
        if(position[zeros[i]] == n):
            position[zeros[i]] = i
    mx = 1
    for i in range(n):

        if zeros[i] <= k:
            pos = 0
            mx = max(mx, i - pos + 1)
        else:
            pos = position[zeros[i-k]]
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