while 1:
    num1, num2 = map(int, input("Input two numbers: ").split())

    if(num1 > num2):
        a = num1
        num1 = num2
        num2 = a

    for i in range(num1+1, num2):
        count = 0
        for j in range(1,i+1):
            if (i%j == 0):
                count += 1
        if(count<3 and i != 1 and i != 0 ):
            print(i, end = " ")
    

    
    print("\n")
    

