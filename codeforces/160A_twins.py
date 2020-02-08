n = int(input())
l = list(map(int , input().split()))
s=0
count=0
x = sum(l)
l.sort()
d = l[::-1]
i=0
while(s <= x/2):
    s+=d[i]
    i+=1
    count+=1
print(count)
    
