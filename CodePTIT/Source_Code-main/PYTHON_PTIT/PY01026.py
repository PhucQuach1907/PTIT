def Solve(tc):
    a = input()
    b = input()
    print("Test %s: %s" % (tc, "YES" if sorted(
        list(a)) == sorted(list(b)) else "NO"))


for i in range(int(input())):
    Solve(i+1)
