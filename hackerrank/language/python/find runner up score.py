n = int(input())                                   #initialising number of elements in list
l = list(map(int,input().strip().split()))[:n]     
large = max(l)                                     #initialising large as an element
for i in l:                                         #for loop to check max
  if(large == max(l)):
      l.remove(max(l))
 print(max(l))
