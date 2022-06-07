while 1:
    
    usage = int(input("Input usage: "))
    var1 = 80
    var2 = 120
    var3 = 250
    if(usage<=100):
        charge = usage*var1
        print(usage ,"*" ,var1,"=",charge)
    elif(usage<=200):
        re1 =usage//100
        if(re1 > 0):
            re1 = 100
            charge1 = var1*100
            
        re2 =usage%100
        charge2 = re2*var2

        print(re1,"*" ,var1," + ",re2,"*", var2,"=",charge1+charge2)
    else:
        re1 =usage//100
        if(re1 > 0):
            re1 = 100
            charge1 = var1*100
            
        re2 =usage//100
        if(re2 > 1):
            re2 = 100
            charge2 = var2*100

        res= usage%200
        charge3 = res*var3
        print(re1,"*",var1," + ",re1,"*",var2," + ",res,"*",var3,"=",charge1+charge2+charge3)
    
