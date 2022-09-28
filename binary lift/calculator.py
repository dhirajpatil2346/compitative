s = input()
list1 = list(s.split(" "))
# print(list1)
n = int(list1[0])
p=int(list1[1])
print(list1)
c = input()
if(c=='*'):
    print(n*p)
elif(c=='/'):
    print(n/p)
elif(c=="+"):
    print(n+p)
elif(c=='-'):
    print(n-p)
elif(ch="//"):
    print(n//p)