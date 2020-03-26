t = int(input())
for i in range(t):
    s = int(input())
    if(s<1500):
        hra = 0.1 * float(s)
        da = 0.9 * float(s)
        print(s + hra + da)
    else:
        print(500 + float(s)*1.98)
