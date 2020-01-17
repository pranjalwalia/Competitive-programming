s = str(input())
v = [ 'a' , 'e' , 'i' , 'o' , 'u' , 'A' , 'E' , 'I' , 'O' , 'U' , 'y' , 'Y' ]
d = []
for i in s:
    d.append(i.lower())

s1 = ''

for i in d:
    if(i in v):
        continue
    else:
        s1 = s1 + '.' + str(i)
print(s1)
