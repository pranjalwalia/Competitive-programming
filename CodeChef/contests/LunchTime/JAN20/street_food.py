t = int(input())
for i in range(t):
    l = []
    n = int(input())
    for i in range(n):
        d = list(map(int, input().split()))
        l.append(d)
    p = []
    for i in l:
        for j in i:
            p.append( (i[1]//(i[0]+1) )*i[2] )
    print(max(p))


