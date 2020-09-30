def journeyToMoon(n, c):
    x=[]
    v=0
    rs=0
    m=0
    f={}
    a1=0
    b1=0
    a=0
    b=0
    p=-1
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
                m+=2
                
            elif(a1==1 and b1==0):
                x[a][c[j][1]]=1
                f[c[j][1]]=a
                m+=1
                
            elif(a1==0 and b1==1):
                x[b][c[j][0]]=1
                f[c[j][0]]=b
                m+=1
                
            elif(a1==1 and b1==1 and a!=b):
                x[a].update(x[b])
                s=list(x[b].keys())
                for i in range (len(s)):
                    f[s[i]]=a
                    
                x[b].clear()
    if(m<n):
        v=n-m
    print(m,v)
    if(v==0):
        for i in range(len(x)):
            rs+=(len(x[i])*(m-len(x[i])))
            m-=len(x[i])
    else:
        for i in range(len(x)):
            rs+=(len(x[i])*(m-len(x[i])+v))
            m-=len(x[i])
        rs+=(v*(v-1))/2
    return(int(rs))
