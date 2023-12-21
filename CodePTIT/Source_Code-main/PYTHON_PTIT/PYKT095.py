class Customer:
    def __init__(self, orderNumber, name, type, first, last):
        dm = [100, 500, 200]
        self.code = "KH%02d" % (orderNumber)
        self.name = name
        self.type = type
        self.sodien = int(last) - int(first)
        self.dinhmuc = dm[ord(type)-ord("A")]

    def getFormattedName(self):
        w = self.name.strip().lower().split()
        return " ".join(w).title()

    def trongdinhmuc(self):
        return 450 * (self.sodien if self.sodien < self.dinhmuc else self.dinhmuc)

    def vuotdinhmuc(self):
        return max(0, (self.sodien-self.dinhmuc)*1000)

    def vat(self):
        return self.vuotdinhmuc()//20

    def total(self):
        return self.trongdinhmuc() + self.vuotdinhmuc() + self.vat()

    def __str__(self):
        return "%s %s %s %s %s %s" % (self.code, self.getFormattedName(), self.trongdinhmuc(), self.vuotdinhmuc(), self.vat(), self.total())


if __name__ == "__main__":
    n = int(input())
    customerList = []
    for i in range(n):
        name = input()
        type, first, last = input().split()
        customerList.append(Customer(i+1, name, type, first, last))
    customerList.sort(key=lambda x: -x.total())
    for c in customerList:
        print(c)
