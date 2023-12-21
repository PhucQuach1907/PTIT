class Customer:
    def __init__(self, orderNumber, name, oldIndex, newIndex):
        self.code = "KH%02d" % (orderNumber)
        self.name = name
        self.used = newIndex - oldIndex

    def getSurcharge(self):
        if (self.used > 100):
            return 5
        if (self.used > 50):
            return 3
        return 2

    def getTotal(self):
        cost, tmpUsed = 0, self.used
        if tmpUsed > 100:
            tmp = tmpUsed - 100
            cost += 200 * tmp
            tmpUsed -= tmp
        if tmpUsed > 50:
            tmp = tmpUsed - 50
            cost += 150 * tmp
            tmpUsed -= tmp
        if tmpUsed > 0:
            cost += 100 * tmpUsed
        return round(cost + (cost * self.getSurcharge() / 100))

    def __str__(self):
        return "%s %s %s" % (self.code, self.name, self.getTotal())


if __name__ == "__main__":
    arr = []
    for i in range(int(input())):
        arr.append(Customer(i+1, input(), int(input()), int(input())))
    arr.sort(key=lambda x: (-x.getTotal()))
    for x in arr:
        print(x)
