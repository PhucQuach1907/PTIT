n = int(input())
matrix = [[int(x) for x in input().split()] for y in range(n)]
k = int(input())
up, down = 0, 0
for i in range(n):
    for j in range(n):
        if i+j+2 < n+1:
            up += matrix[i][j]
        elif i+j+2 > n+1:
            down += matrix[i][j]
print("YES" if abs(up-down) <= k else "NO")
print(abs(up-down))
