s1 = str(input())
s2 = str(input())
s3 = str(input())
l1 = []
l2 = []
s4 = s1+s2

for i in s4:
    l1.append(i)

l1.sort()

for i in s3:
    l2.append(i)

l2.sort()

if(l1==l2):
    print('YES')
else:
    print('NO')    
