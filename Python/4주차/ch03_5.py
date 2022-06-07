year = int(input("Input year : "))
result = ((year%4 == 0) and (year%400 == 0)) or (year%100 != 0)
print(result)
