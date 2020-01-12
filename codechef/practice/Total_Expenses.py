t = int(input())
for i in range(t):
    x,y = map(float , input().split())
    if(x <= 1000): 
        print ('%.6f'%(x*y)) 
    else:
        print('%.6f' % (0.9 * x * y))
