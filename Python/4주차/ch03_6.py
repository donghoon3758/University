
money = int(input("Input withdrawal amount : "))

c500 = money // 500
money  = money % 500

c100 = money //100
money  = money % 100

c50 = money //50
money  = money % 50


c10 = money //10
money  = money % 10

c5 = money // 5
money  = money % 5


print("1 won: ", money)
print("5 won: ", c5)
print("10 won: ", c10)
print("50 won: ", c50)
print("100 won: ", c100)
print("500 won: ", c500)
print("Total number of coins: ", c500 + c100 + c50 + c10 + c5 + money)
