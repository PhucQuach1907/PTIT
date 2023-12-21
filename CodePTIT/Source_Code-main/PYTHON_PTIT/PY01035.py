nmc = "01234567"

num = int(input(), 2)
res = ""
while num:
    res += nmc[num % 8]
    num //= 8
print(res[::-1])
