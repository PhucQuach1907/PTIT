class Staff:
    def __init__(self, code, name, nameGroup, basicSalary, dayWorked):
        self.code = code
        self.name = name
        self.nameGroup = nameGroup
        self.basicSalary = int(basicSalary)
        self.dayWorked = int(dayWorked)

    def getSalary(self):
        gradeTable = [[10, 12, 14, 20], [10, 11, 13, 16],
                      [9, 10, 12, 14], [8, 9, 11, 13]]
        grade = -1
        if int(self.code[1:3]) >= 16:
            grade = gradeTable[ord(self.code[0])-ord("A")][3]
        elif int(self.code[1:3]) >= 9:
            grade = gradeTable[ord(self.code[0])-ord("A")][2]
        elif int(self.code[1:3]) >= 4:
            grade = gradeTable[ord(self.code[0])-ord("A")][1]
        else:
            grade = gradeTable[ord(self.code[0])-ord("A")][0]
        return self.basicSalary * self.dayWorked * grade * 1000

    def __str__(self):
        return "%s %s %s %s" % (self.code, self.name, self.nameGroup, self.getSalary())


if __name__ == "__main__":
    n = int(input())
    myDict = {}
    for i in range(n):
        code, name = input().split(" ", 1)
        myDict[code] = name
    m = int(input())
    staffList = []
    for i in range(m):
        code, name, basicSalary, dayWorked = input(), input(), input(), input()
        staffList.append(
            Staff(code, name, myDict[code[-2::1]], basicSalary, dayWorked))
    for staff in staffList:
        print(staff)
