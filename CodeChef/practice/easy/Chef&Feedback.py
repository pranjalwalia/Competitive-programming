t = int(input())
for i in range(t):
    s = str(input())
    s1 = '010'
    s2 = '101'
    if(s1 in s or s2 in s):
        print("Good")
    else:
        print("Bad")
