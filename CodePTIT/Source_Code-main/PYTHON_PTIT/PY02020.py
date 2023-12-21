n = int(input())
arr = list(map(float, input().split()))
sum, cnt = 0.0, 0

for x in arr:
    if x != max(arr) and x != min(arr):
        sum += x
        cnt += 1
print("%.2f" % (sum/cnt))
