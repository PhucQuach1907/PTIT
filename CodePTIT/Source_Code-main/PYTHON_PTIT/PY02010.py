while True:
    n = int(input())
    if n == 0:
        break
    arr = [int(input()) for i in range(n)]
    mn, mx = min(arr), max(arr)
    if mn == mx:
        print("BANG NHAU")
    else:
        print(mn, mx, sep=" ")
