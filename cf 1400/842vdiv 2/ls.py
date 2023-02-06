for j in range(int(input())):
    lst1 = list(map(int, input().split()));
    lst = list(map(int, input().split()));
    n = int(lst1[0])
    m = int(lst1[1])
    # print(lst)
    i = 0
    c=0
    curr=1
    for i in range(len(lst)):
        if(lst[i]==curr):
            curr+=1
            c+=1
    p = n -c
    if(p%m>=1):
        print(int(int(p/m) +1))
    else:
        print(int(p/m))
