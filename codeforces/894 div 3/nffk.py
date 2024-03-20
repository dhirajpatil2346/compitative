# Read the number of test cases
t = int(input())

# Iterate through each test case
for _ in range(t):
    n = int(input())  # Number of ice cream types
    
    # Binary search to find the minimum x (number of balls)
    low = 1
    high = 10**9  # A large upper bound to start the binary search
    
    while low < high:
        mid = (low + high) // 2
        ice_cream_types = mid * (mid - 1) // 2
        
        if ice_cream_types >= n:
            high = mid
        else:
            low = mid + 1
    # The minimum number of balls needed is low
    print(low)
