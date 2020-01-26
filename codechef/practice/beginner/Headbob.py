t = int(input())
for i in range(t):
    l = int(input())
    s = str(input())
    count1=0
    count2=0
    count3=0
    count4=0
    for i in s:
        
        if(i == 'I'):
            count1+=1
        
        if( i == 'Y'):
            count3+=1
        if(i=='N'):
            count4+=1
    
    # print(count1)
    # print(count3)
    # print(count4)

    # if(count1!=0):
    #     print("INDIAN")
    
    # elif(count4==l or count3==l):
    #     print('NOT SURE')
    #     break
            
    # elif(count3!=0 and count4!=0):
    #     print("NOT INDIAN")

    if(count1!=0):
        print("INDIAN")
    elif(count3!=0):
        print("NOT INDIAN")
    else:
        print("NOT SURE")
