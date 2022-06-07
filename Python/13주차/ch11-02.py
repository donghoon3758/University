import datetime as dt
import time as t

check=0
prevEnd = []
def calc(timeList):
    second = 0
    start = dt.datetime.strptime(timeList[0], "%H:%M:%S")
    end = dt.datetime.strptime(timeList[1], "%H:%M:%S")

    time_9 = dt.datetime.strptime("09:00:00", "%H:%M:%S")
    time_18 = dt.datetime.strptime("18:00:00", "%H:%M:%S")

    if (start < time_9 and start < time_18):
        if (end > time_18):
            second = ((time_9 - start).seconds * 2) + (time_18 - time_9).seconds + ((end - time_18).seconds) * 2
        elif(end<time_18 and end > time_9):
            second = ((time_9 - start).seconds) * 2 + (end - time_9).seconds
        elif(end<time_9):
            second = ((end-start).seconds)*2
    elif (start >= time_9 and start < time_18):
        if (end > time_18):
            if check==0:
                second = (time_18 - start).seconds + ((end - time_18).seconds) * 2
                second -= ((start - time_9).seconds) * 5
            elif not(check==0):
                second = (time_18 - start).seconds + ((end - time_18).seconds) * 2
                second -= ((start - prevEnd).seconds) * 5
        else:
            if check==0:
                second = (end - start).seconds
                second -= ((start - time_9).seconds) * 5
            elif not(check == 0):
                second = (end - start).seconds
                second -= ((start - prevEnd).seconds) * 5
    elif (start >= time_18):
        if(check==0):
            second = ((end - start).seconds) * 2
            second -= ((time_18-time_9).seconds)*5
        else:
            second = ((end-start).seconds)*2

    return second


n = int(input())

input_list = [input() for _ in range(n)]
sum = 0
for i in range(n):
    newList = input_list[i].split(" ")
    sum += calc(newList)
    prevEnd = dt.datetime.strptime(newList[1], "%H:%M:%S")
    if(dt.datetime.strptime(newList[0], "%H:%M:%S")>=dt.datetime.strptime("09:00:00", "%H:%M:%S") or dt.datetime.strptime(newList[1], "%H:%M:%S")>=dt.datetime.strptime("09:00:00", "%H:%M:%S") and dt.datetime.strptime(newList[0], "%H:%M:%S")<=dt.datetime.strptime("18:00:00", "%H:%M:%S")):
        check+=1

print(sum)
