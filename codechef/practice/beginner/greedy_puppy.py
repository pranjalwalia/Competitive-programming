t = int(input())
for i in range(t):
    n,k = map(int, input().split())
    l = []
    for j in range(1,k+1):
        l.append(n%j)
    print(max(l))
