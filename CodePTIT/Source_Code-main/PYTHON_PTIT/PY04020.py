class Commodity:
    def __init__(self, code, name, quantity, unitPrice, discount):
        self.code = code
        self.name = name
        self.quantity = int(quantity)
        self.unitPrice = int(unitPrice)
        self.discount = int(discount)

    def getSubtotal(self):
        return self.quantity * self.unitPrice - self.discount

    def __str__(self):
        return "%s %s %s %s %s %s" % (self.code, self.name, self.quantity, self.unitPrice, self.discount, self.getSubtotal())


if __name__ == "__main__":
    n = int(input())
    commodities = []
    for i in range(n):
        commodities.append(
            Commodity(input(), input(), input(), input(), input()))
    commodities.sort(key=lambda x: x.getSubtotal(), reverse=True)
    for commodity in commodities:
        print(commodity)
