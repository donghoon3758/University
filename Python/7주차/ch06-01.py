while 1:
    num1, num2 = map(int, input("Input two numbers: ").split())
    count = num2-num1 +1
    if(num1 > num2):
        a = num1
        num1 = num2
        num2 = a
    num1= num1+1
    for num1 in range(num1, num2, 1):
        if(num1 % 2 == 1):
            if(num1 == num2 or num1 == num2-1 or num1 == num2-2):
             print(num1, end='\n')
            else:
                print(num1, end=', ')
        

    
