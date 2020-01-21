s = str(input())
l = s.split('+')
l.sort()
for i in range(len(l)):
    # print(int(i))
    if(i < len(l)-1):
        print( l[int(i)] + '+' , end = '')
    elif(i == len(l)-1):
        print(l[int(i)])
