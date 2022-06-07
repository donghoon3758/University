while 1:
    
    A, B, C, D = map(int, input("Input heights: ").split())


    list = [A, B, C, D]
    sortedList=sorted(list,reverse = True)
    resultList = [A,B,C,D]
    if(sortedList[0] == A):
        resultList[0] = "A"
    elif(sortedList[0] == B):
         resultList[0] = "B"
    elif(sortedList[0] == C):
         resultList[0] = "C"
    elif(sortedList[0] == D):
         resultList[0] = "D"
     
    if(sortedList[1] == A):
       resultList[1] = "A"
    elif(sortedList[1] == B):
        resultList[1] = "B"
    elif(sortedList[1] == C):
        resultList[1] = "C"
    elif(sortedList[1] == D):
        resultList[1] = "D"
    
    if(sortedList[2] == A):
        resultList[2] = "A"
    elif(sortedList[2] == B):
        resultList[2] = "B"
    elif(sortedList[2] == C):
        resultList[2] = "C"
    elif(sortedList[2] == D):
        resultList[2] = "D"
    
    if(sortedList[3] == A):
        resultList[3] = "A"
    elif(sortedList[3] == B):
        resultList[3] = "B"
    elif(sortedList[3] == C):
        resultList[3] = "C"
    elif(sortedList[3] == D):
        resultList[3] = "D"

    print(resultList[0],',',resultList[1],',',resultList[2],',',resultList[3])
