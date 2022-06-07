year,month,date = map(int,input().split("-"))
month_days = [31,28,31,30,31,30,31,31,30,31,30,31]

if(date>31 or date <=0):
    print("Input error")
elif(month>12 or month<1):
    print("Input error")
elif(year>2022 or year<=0000):
    print("Input error")
elif(year==2022 and month>5):
    print("Input error")
elif(not(year%4==0 or year%400==0 and year%100!=0) and month==2 and date>2):
    print("Input error")
else:
    days = 0
    for i in range(1,year):
        if(i%4==0 or i%400==0 and i%100!=0):
            days+=366
        else:
            days+=365

    for i in range(1,month):
        days += month_days[i-1]

    if(month>=3):
        if(year%4==0 or year%400==0 and year%100!=0):
            days+=1

    days+=date
    days-=1

    if(days%7==1):
        print("MON")
    elif(days%7==2):
        print("TUE")
    elif(days%7==3):
        print("WED")
    elif(days%7==4):
        print("THU")
    elif(days%7==5):
        print("FRI")
    elif(days%7==6):
        print("SAT")
    elif(days%7==0):
        print("SUN")
