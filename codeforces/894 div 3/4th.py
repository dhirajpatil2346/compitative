for t  in range(int(input())):
    x = int(input())
    l = 1 
    r = 1e18
    ans = 1e18
    while(l<=r):
        mid =int((l+r)/2)
        if((((mid*(mid-1)))  >= (2*x))):
            ans = mid
            r = mid - 1
        else:
            l = mid+1
    print(ans)
