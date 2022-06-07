def sumNum(tel):
    sum = 0
    tel = tel.split("-")
    secontCnt = len(tel[1])
    thirdCnt = len(tel[2])
    fourthCnt = len(tel[3])
    first = int(tel[0])
    second = indexDigitSum(tel, 1, secontCnt)
    third = indexDigitSum(tel, 2, thirdCnt)
    fourth = indexDigitSum(tel, 3, fourthCnt)
    sum = first + second + third + fourth
    return sum
def indexDigitSum(tel, index, cnt):
    result = 0
    i = 0
    for i in range(cnt):
        result += int(tel[index][i])
    return result
def exchange(tel, index, value):
    listTel = []
    listTel = list(tel)
    listTel[index] = value
    tel = "".join(listTel)
    return tel
def alphaToNum(tel):
    while 1:
        two = list(filter(lambda x: tel[x] == 'A' or tel[x] == 'B' or tel[x] == 'C',range(len(tel))))
        i=0
        for i in range(len(two)):
            if(not(two[i]==-1)):
                tel = exchange(tel, two[i], '2')

        i = 0
        three = list(filter(lambda x: tel[x] == 'D' or tel[x] == 'E' or tel[x] == 'F',range(len(tel))))
        for i in range(len(three)):
            if (not(three[i] == -1)):
                tel = exchange(tel, three[i], '3')

        i = 0
        four = list(filter(lambda x: tel[x] == 'G' or tel[x] == 'H' or tel[x] == 'I',range(len(tel))))
        for i in range(len(four)):
            if (not(four[i] == -1)):
                tel = exchange(tel, four[i], '4')

        i = 0
        five = list(filter(lambda x: tel[x] == 'J' or tel[x] == 'K' or tel[x] == 'L',range(len(tel))))
        for i in range(len(five)):
            if (not(five[i] == -1)):
                tel = exchange(tel, five[i], '5')

        i = 0
        six = list(filter(lambda x: tel[x] == 'M' or tel[x] == 'N' or tel[x] == 'O',range(len(tel))))
        for i in range(len(six)):
            if (not(six[i] == -1)):
                tel = exchange(tel, six[i], '6')

        i = 0
        seven = list(filter(lambda x: tel[x] == 'P' or tel[x] == 'Q' or tel[x] == 'R' or tel[x] =='S',range(len(tel))))
        for i in range(len(seven)):
            if (not(seven[i] == -1)):
                tel = exchange(tel, seven[i], '7')

        i = 0
        eight = list(filter(lambda x: tel[x] == 'T' or tel[x] == 'U' or tel[x] == 'V',range(len(tel))))
        for i in range(len(eight)):
            if (not(eight[i] == -1)):
                tel = exchange(tel, eight[i], '8')

        i = 0
        nine = list(filter(lambda x: tel[x] == 'W' or tel[x] == 'X' or tel[x] == 'Y' or tel[x] == 'Z',range(len(tel))))
        for i in range(len(nine)):
            if (not(nine[i] == -1)):
                tel = exchange(tel, nine[i], '9')
        break
    return tel


while 1:
    tel = input("Input telephone number: ")
    if(len(tel)==14 and len(tel.split("-")) == 4):
        tel = alphaToNum(tel)
        print(sumNum(tel))
    else:
        print("Input error")

