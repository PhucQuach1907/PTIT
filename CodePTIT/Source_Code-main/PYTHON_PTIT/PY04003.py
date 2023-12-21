import math


class PhanSo:
    def __init__(self, tu, mau):
        self.tu = tu
        self.mau = mau

    def rutgon(self):
        tmp = math.gcd(self.tu, self.mau)
        self.tu //= tmp
        self.mau //= tmp

    def __str__(self):
        return "%s/%s" % (self.tu, self.mau)


tu, mau = map(int, input().split())
p = PhanSo(tu, mau)
p.rutgon()
print(p)
