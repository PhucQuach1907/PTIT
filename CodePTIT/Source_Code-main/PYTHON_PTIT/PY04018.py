class Teacher:
    def __init__(self, orderNumber, name, code, p1, p2):
        self.c = "GV%02d" % (orderNumber)
        self.name = name
        self.code = code
        self.p1 = float(p1)
        self.p2 = float(p2)

    def getSubject(self):
        subjects = ["TOAN", "LY", "HOA"]
        return subjects[ord(self.code[0])-ord('A')]

    def getPriorityPoint(self):
        pri = [2.0, 1.5, 1.0, 0.0]
        return pri[int(self.code[1])-1]

    def getTotalPoint(self):
        return self.p1*2 + self.p2 + self.getPriorityPoint()

    def getStatus(self):
        return "TRUNG TUYEN" if self.getTotalPoint() >= 18 else "LOAI"

    def __str__(self):
        return "%s %s %s %.1f %s" % (self.c, self.name, self.getSubject(), self.getTotalPoint(), self.getStatus())


if __name__ == "__main__":
    n = int(input())
    teachers = []
    for i in range(n):
        teachers.append(Teacher(i+1, input(), input(), input(), input()))
    teachers.sort(key=lambda x: x.getTotalPoint(), reverse=True)
    for teacher in teachers:
        print(teacher)
