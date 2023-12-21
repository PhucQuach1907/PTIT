from decimal import ROUND_HALF_UP, Decimal


class Student:
    def __init__(self, orderNumber, name, pointList):
        self.code = "HS%02d" % (orderNumber)
        self.name = name
        self.pointList = pointList

    def getAverage(self):
        res = self.pointList[0]*2 + self.pointList[1]*2
        for i in range(2, 10):
            res += self.pointList[i]
        res /= 12
        return res.quantize(Decimal('0.1'), ROUND_HALF_UP)

    def getClassification(self):
        p = self.getAverage()
        if p >= 9:
            return "XUAT SAC"
        if p >= 8:
            return "GIOI"
        if p >= 7:
            return "KHA"
        if p >= 5:
            return "TB"
        return "YEU"

    def __str__(self):
        return "%s %s %s %s" % (self.code, self.name, self.getAverage(), self.getClassification())


if __name__ == "__main__":
    studentArr = []
    for i in range(int(input())):
        studentArr.append(
            Student(i+1, input(), [Decimal(x) for x in input().split()]))
    studentArr.sort(key=lambda x: (-x.getAverage(), x.code))
    for x in studentArr:
        print(x)
