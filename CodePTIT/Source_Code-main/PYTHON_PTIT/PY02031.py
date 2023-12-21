import math


def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n))+1):
        if n % i == 0:
            return False
    return True


n, m = map(int, input().split())
matrix = [[int(x) for x in input().split()] for y in range(n)]
for i in range(0, n):
    for j in range(0, m):
        matrix[i][j] = 1 if isPrime(matrix[i][j]) else 0

for x in matrix:
    print(*x)
