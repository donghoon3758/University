class car:
    id=0
    price=0
    year=0
    km=0
    def __init__(self,id,price,year,km):
        self.id=id
        self.price=price
        self.year = year
        self.km = km
        print(id,  "added")
    def printInfo(self):
        print("id="+str(self.id)+" | price="+str(self.price)+" | year="+str(self.year)+" | km="+str(self.km))
    def __lt__(self, other):
        if self.price != other.price:
            return self.price < other.price

cars = []
cnt = int(input())
for i in range(cnt):
    id, price, year, km = map(int, input().split())
    cars.append(car(id, price, year, km))
cars.sort(reverse=True)
for c in cars: c.printInfo()
