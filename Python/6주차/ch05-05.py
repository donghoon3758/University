while 1:
    
    var1, var2, var3 = map(int, input("Input angles: ").split())
    if((var1 > 0 and var1 < 180) and (var2 > 0 and var2 < 180) and (var3 > 0 and var3 < 180) and (var1+var2+var3)==180):
        if(var1 == var2 == var3):
            print("Equilateral Triangle")
        elif((var1 ==90 and var2 == 45 and var3 == 45) or(var2 ==90 and var1 == 45 and var3 == 45) or (var3 ==90 and var2 == 45 and var1 == 45)):
            print("Right-angled Isosceles Triangle")
        elif((var1==90 and (var2+var3)==90) or (var2==90 and (var1+var3)==90) or (var3==90 and (var2+var1)==90)):
            print("Right-angled Triangle")
        elif((var1==var2) or (var1 == var3) or (var2 == var3)):
            print("Isosceles Triangle")
        else:
            print("Triangle")
    elif((var1+var2+var3)<180):
        print("Not Triangle")
    else:
        print("Error")
    
           
