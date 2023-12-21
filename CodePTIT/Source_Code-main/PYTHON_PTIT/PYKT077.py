from datetime import datetime


class Lichthi:
    def __init__(self, orderNumber, codeSubject, nameSubject, day, group):
        self.code = "T%03d" % (orderNumber)
        self.codeSubject = codeSubject
        self.nameSubject = nameSubject
        self.dayPrint = day
        self.dayCompare = datetime.strptime(day, "%d/%m/%Y %H:%M")
        self.group = group

    def __str__(self):
        return "%s %s %s %s %s" % (self.code, self.codeSubject, self.nameSubject, self.dayPrint, self.group)


if __name__ == "__main__":
    n, m = map(int, input().split())
    hashSubject = {}
    for i in range(n):
        code, name = input(), input()
        hashSubject[code] = name
    listLichthi = []
    for i in range(m):
        codeSubject, day, hour, group = input().split()
        listLichthi.append(Lichthi(i + 1, codeSubject,
                                   hashSubject[codeSubject], day+" "+hour, group))
    listLichthi.sort(key=lambda x: x.dayCompare)
    for i in listLichthi:
        print(i)
