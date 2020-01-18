t = int(input())
for i in range(t):
    n = int(input())
    l = list(map(int, input().split()))
    l.sort()
    x = abs(l[0]-l[1])
    for j in range(len(l)-1):
        if( 0 <= l[j+1] - l[j] < x ):
            x = l[j+1] - l[j]
    print(x)
