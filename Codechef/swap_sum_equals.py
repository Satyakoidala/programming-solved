t = int(input())
while t>0:
    t-=1
    n = int(input())
    low, high = 1, n
    total = n*(n+1)//2
    if total%2==0:
        half_sum = total//2
        while (low<high):
            # print(low,high)
            mid = (low+high)//2
            mid_sum = mid*(mid+1)//2
            # print(mid_sum)
            if (mid_sum<half_sum):
                low = mid+1
            elif (mid_sum>half_sum):
                high = mid-1
            else:
                print(n-mid+1)
                break
        else:
            low -= 1
            print(n-low)
    else:
        print(0)