while 1:
    score = input("Input scoring results: ")
    
    OScore=score.count('O')
    XScore = score.count('X')

    print(OScore>XScore)


