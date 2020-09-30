def almostSorted(a):
    b=a.copy()
    b.sort()
    c=0
    e=0
    n=[]
    for i in range (len(a)):
        if(b[i]!=a[i]):
            n.append(i)
    if(len(n)==2):
        print("yes")
        print("swap",n[0]+1,n[-1]+1)
        e=1
    else:
        r=sorted(a[n[0]:n[-1]+1],reverse=True)
        if(r==a[n[0]:n[-1]+1]):
            print("yes")
            print("reverse",n[0]+1,n[-1]+1)
            e=1

    if(e==0):
        print("no")
