def roadsAndLibraries(n, cl, r, c):
    x=[]
    f={}
    a1=0
    b1=0
    a=0
    b=0
    p=-1
    
    if(cl<r or cl==r):
        return(n*cl)
    else:
        for j in range (len(c)):
            try:
                a=f[c[j][0]]
                a1=1
                
            except:
                a1=0
                
            try:
                b=f[c[j][1]]
                b1=1
                
            except:
                b1=0
                
            
            if(a1==0 and b1==0):
                l={c[j][1]:1, c[j][0]:1}
                x.append(l)
                p+=1
                f[c[j][1]]=p
                f[c[j][0]]=p
                
            elif(a1==1 and b1==0):
                x[a][c[j][1]]=1
                f[c[j][1]]=a
                
            elif(a1==0 and b1==1):
                x[b][c[j][0]]=1
                f[c[j][0]]=b
                
            elif(a1==1 and b1==1 and a!=b):
                x[a].update(x[b])
                s=list(x[b].keys())
                for i in range (len(s)):
                    f[s[i]]=a
                    
                x[b].clear()
                
                
    print(x,f)
    t=0
    z=0
    m=0
    for i in range (len(x)):
        if(len(x[i])!=0):
            t+=len(x[i])-1
            z+=len(x[i])
        else:
            m+=1
    if(z!=n):
        z=n-z
        v=(t*r) + (z*cl) + (cl*(len(x)-m))
        print("if")
    else:
        v=(t*r) + ((len(x)-m)*cl)
        print("else",len(x))
    return(v)
