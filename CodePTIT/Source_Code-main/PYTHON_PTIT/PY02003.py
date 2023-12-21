pow2 = [2**x for x in range(66)]
pow3 = [3**x for x in range(39)]
pow5 = [5**x for x in range(27)]
proccess = set()
for i in range(0, 65):
    for j in range(0, 38):
        for k in range(0, 26):
            tmp = pow2[i]*pow3[j]*pow5[k]
            if tmp <= 1e18:
                proccess.add(tmp)

hamming = list(sorted(proccess))
res = {}
for i in range(0, len(hamming)):
    res[hamming[i]] = i+1


def Solve():
    ans = res.get(int(input()))
    print(ans if ans != None else "Not in sequence")


for i in range(0, int(input())):
    Solve()
