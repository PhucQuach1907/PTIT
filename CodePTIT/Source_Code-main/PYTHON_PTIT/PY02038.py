n = int(input())
matrix = [input() for _ in range(n)]
res = 0
for x in matrix:
    coin = x.count("C")
    res += coin*(coin-1)//2
for col in range(n):
    coin = 0
    for row in range(n):
        coin += 1 if matrix[row][col] == "C" else 0
    res += coin*(coin-1)//2
print(res)
