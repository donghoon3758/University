print("## Plesae enter the information to send the two items. ##")
recipient = input("Recipient:")
address = input("Address:")
item1 = int(input("Weight(g) of iten #1:"))
item2 = int(input("Weight(g) of iten #2:"))
print("-------------------------------")
print("**TO ==>" + recipient)
print("**Address ==> " + address)
result = (item1+item2)/2
print("**Total shipping cost ==> ", result)


