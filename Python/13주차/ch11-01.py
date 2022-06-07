import datetime as dt

def calc(inputDate, revise):
    t = int(revise[1:len(revise)-1])
    if(revise.endswith("h")):
        delta = dt.timedelta(hours=t)
    elif(revise.endswith("M")):
        delta = dt.timedelta(minutes=t)
    elif(revise.endswith("d")):
        delta = dt.timedelta(days=t)
    else:
        delta = dt.timedelta(seconds=t)
    if(revise.startswith("+")):
        return inputDate+delta
    else:
        return inputDate-delta
inputValue = list(input().split(" "))
date = list(inputValue[0].split("-"))
time= list(inputValue[1].split(":"))

inputDate = dt.datetime(int(date[0]),int(date[1]),int(date[2]),int(time[0]),int(time[1]),int(time[2]))

hms =  [input() for _ in range(int(inputValue[2]))]
for i in range(int(inputValue[2])):
    inputDate = calc(inputDate,hms[i])
    print(inputDate.strftime("%Y/%m/%d %H-%M-%S"))



