while 1:
    
    num = int(input("input height: "))
    space=1
    for i in range(num,0,-1):
        print(i,end='')
        for k in range(0,space):
            print(' ',end='')
         
        for k in range(0,i-1):
            print("*",end='')
        print(i,end='')
        for k in range(0,i-1):
            print("*",end='')
        print()
        space+=1
    
