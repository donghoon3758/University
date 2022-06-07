while 1:
    
    var1, var2, var3 = map(int, input("Input length of sides: ").split())
    list = [var1,var2,var3]
    list.sort()
    
    if((list[0] != 0) and (list[1] != 0) and (list[2] != 0)):
        if(list[0]+list[1] <= list[2]):
            print("Not Triangle")
        elif(list[0] == list[1] == list[2]):
            print("Equilateral Triangle")
        elif((list[0]**2 + list[1]**2)== list[2]**2):
            print("Right-angled Triangle")
        elif((list[0] == list[1]) or (list[1] == list[2])):
            print("Isosceles Triangle")
        else:
            print("Triangle")
    else:
        print("Error")
    
           
