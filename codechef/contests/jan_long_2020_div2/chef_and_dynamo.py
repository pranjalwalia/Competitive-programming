import sys
import os

t = int(input())
for i in range(t):
    n = int(input())
    a = int(input())
    s = 2*(10**n) + a
    print(s)
    b = int(input())
    c = 10**n -b
    print(c)
    d = int(input())
    e = 10**n -d
    print(e)
    x = int(input())
    sys.stdout.flush()


    if(x == -1):
        sys.exit()
