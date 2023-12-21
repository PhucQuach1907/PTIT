from functools import cmp_to_key


class Student:
    def __init__(self, name, accepted, submit):
        self.name = name
        self.accepted = accepted
        self.submit = submit

    def __str__(self):
        return "%s %s %s" % (self.name, self.accepted, self.submit)


def compare(x, y):
    if x.accepted != y.accepted:
        return y.accepted - x.accepted
    if x.submit != y.submit:
        return x.submit - y.submit
    if x.name > y.name:
        return 1
    return -1


if __name__ == "__main__":
    n = int(input())
    arr = []
    for i in range(n):
        name = input()
        accepted, submit = map(int, input().split())
        arr.append(Student(name, accepted, submit))
    arr.sort(key=cmp_to_key(compare))
    for x in arr:
        print(x)
