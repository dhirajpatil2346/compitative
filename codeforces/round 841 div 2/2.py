m = 1e9+7
t = int(input())
for i in range(t):
    j = int(input())
    k = (((j * (j+1)) % m) * (4*j - 1)) % m

    print(int((k * 337) ))