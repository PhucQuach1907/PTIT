n, m = map(int, input().split())
matrix = [[int(x) for x in input().split()]for i in range(n)]
minElement, maxElement = 1000000, -1
for x in matrix:
    minElement = min(minElement, min(x))
    maxElement = max(maxElement, max(x))
maxDiff = -1
for i in range(n):
    for j in range(m):
        if matrix[i][j] == maxElement-minElement:
            maxDiff = max(maxDiff, matrix[i][j])
if maxDiff == -1:
    print("NOT FOUND")
else:
    print(maxDiff)
    for i in range(n):
        for j in range(m):
            if matrix[i][j] == maxDiff:
                print("Vi tri [%s][%s]" % (i, j))
