str = input()
lower = 0
for i in range(0, len(str)):
    lower += 1 if str[i].islower() else 0
upper = len(str) - lower
print(str.lower() if lower >= upper else str.upper())
