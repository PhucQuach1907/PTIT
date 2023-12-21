p1 = input()
p2 = input()
pos = int(input())
print(p1[:pos-1]+p2+p1[pos-1::])
