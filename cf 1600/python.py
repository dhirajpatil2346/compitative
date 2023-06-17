a = str(bin(56678))
b = str(bin(764422))
a = (a[2:])
b = (b[2:])
diff = abs(len(a)-len(b))
s = ""
for _ in range(diff):
    s=s+"0"
a = s+a
print(a)
print(b)
# 10111111111101100110
# 10111010101000000110
'''
1+8+16+128
'''