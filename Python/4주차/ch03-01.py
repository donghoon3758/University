num1 =int(input("Input number1 : "))
num2 = int(input("Input number2 : "))


thousands = num2//1000
hundread = (num2%1000)//100
ten = (num2%100)//10
one = num2%10

oneResult = num1 * one
tenResult = num1 * ten
hundreadResult = num1 * hundread
thousandsResult = num1 * thousands



print(oneResult)
print(tenResult)
print(hundreadResult)
print(thousandsResult)
result=int(num1)*int(num2)
print(result)
