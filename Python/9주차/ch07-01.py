while 1:
    str1 = input("Input string 1:")
    str2 = input("Input string 2:")

    list1 = str1.split()
    list2 = str2.split()

    result = [0]
    if(len(list1) > len(list2)):
        length = len(list1)
        plusIndex = len(list1)-len(list2)
        for i in range (0,plusIndex):
            list2.append('')
    else:
        length = len(list2)
        plusIndex = len(list2)-len(list1)
        for i in range (0,plusIndex):
            list1.append('')
    for i in range(0,length,1):
        result[i] = list1[i]+list2[i]
        if(not(i == (length-1))):
            result.append(0)


    print(result)
