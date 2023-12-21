while(True):
    n = int(input())
    if n == 0:
        break
    res = set()
    res.add(n)
    while n != 1:
        if n % 2 == 0:
            n //= 2
            res.add(n)
        else:
            n = n*3+1
            res.add(n)
    print(len(res))
