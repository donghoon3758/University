hour1 = int(input("Input hours for t1 : "))
minute1 = int(input("Input minutes for t1 : "))
second1 = int(input("Input seconds for t1 : "))
hour2 = int(input("Input hours for t2 : "))
minute2 = int(input("Input minutes for t2 : "))
second2 = int(input("Input seconds for t2 : "))


secondResult = (second1 + second2)%60
excessSecond=(second1 + second2)//60


minuteResult = ((minute1 + minute2)+ excessSecond) %60
excessMinute=((minute1 + minute2)+ excessSecond)//60

hourResult = (hour1 + hour2) +excessMinute

print(hourResult," : ", minuteResult, " : ", secondResult)
