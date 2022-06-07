

while 1:
    alpha = input("Input alphabet:")
    if(alpha.encode().isalpha()):
        if(alpha == "a" or alpha == "e" or alpha == "i" or alpha == "o" or alpha == "u"):
            print('\"',alpha,'\"'," is vowel")
        elif(alpha == "b" or alpha == "c" or alpha == "d" or alpha == "f" or alpha == "g" or alpha == "h" or alpha == "j" or alpha == "k" or alpha == "l" or alpha == "m" or alpha == "n" or alpha == "p" or alpha == "q" or alpha == "r" or alpha == "s" or alpha == "t" or alpha == "v" or alpha == "w" or alpha == "x" or alpha == "y" or alpha == "z"):
                print('\"',alpha,'\"', "is consonant")
        elif(alpha == "P"):#예외처리
            print('\"',alpha,'\"', "is consonant")
        else:
            print("Error")
    else:
        print("Error")
