class Gamer:
    def __init__(self, code, name, start, stop):
        self.code = code
        self.name = name
        self.start = start
        self.stop = stop
        self.rangeInMinutes = int(
            stop[0:2])*60+int(stop[3:5]) - (int(start[0:2])*60+int(start[3:5]))

    def formatTime(self):
        return "%s gio %s phut" % (self.rangeInMinutes//60, self.rangeInMinutes % 60)

    def __str__(self):
        return "%s %s %s" % (self.code, self.name, self.formatTime())


if __name__ == "__main__":
    n = int(input())
    arr = []
    for i in range(n):
        arr.append(Gamer(input(), input(), input(), input()))
    arr.sort(key=lambda x: x.rangeInMinutes, reverse=True)
    for i in arr:
        print(i)
