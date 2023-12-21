n = int(input())
arr = list(map(int, input().split()))
sortedArr = sorted(arr)
element = sortedArr[n//2] if n & 1 else arr[min(
    arr.index(sortedArr[n//2]), arr.index(sortedArr[n//2-1]))]
step = 0
for x in sortedArr:
    step += abs(x-element)
print(step, element, sep=" ")
