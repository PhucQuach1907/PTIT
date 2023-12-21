while True:
    P = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_."
    tmp = input().split()
    if (tmp[0] == "0"):
        break
    k, arr = int(tmp[0]), list(tmp[1])
    for i in range(0, len(arr)):
        arr[i] = P[(P.find(arr[i])+k) % 28]
    print("".join(arr)[::-1])
