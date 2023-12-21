from bisect import bisect_left as lower_bound


def getSum(BITree, index):
    sum = 0
    while (index > 0):
        sum += BITree[index]
        index -= index & (-index)
    return sum


def updateBIT(BITree, n, index, val):
    while (index <= n):
        BITree[index] += val
        index += index & (-index)


def convert(arr, n):
    tmp = arr[0:n:1]
    tmp.sort()
    for i in range(n):
        arr[i] = lower_bound(tmp, arr[i]) + 1


def getInvCount(arr, n):
    invcount = 0
    convert(arr, n)
    BIT = [0] * (n + 1)
    for i in range(n - 1, -1, -1):
        invcount += getSum(BIT, arr[i] - 1)
        updateBIT(BIT, n, arr[i], 1)
    return invcount


n = int(input())
arr = list(map(int, input().split()))
print(getInvCount(arr, n))
