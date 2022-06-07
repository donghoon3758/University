hour = int(input("Input hours : "))
minute = int(input("Input minutes: "))
second = int(input("Input seconds: "))
elapsed = int(input("Input elapsed seconds : "))

secondResult = (second +elapsed)%60
excessSecond=(second+elapsed)//60


minuteResult = (minute+excessSecond) %60
excessMinute=(minute +excessSecond)//60

hourResult = hour+excessMinute

print(hourResult," : ", minuteResult, " : ", secondResult)
