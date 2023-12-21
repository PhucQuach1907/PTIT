MOD = 10**9 + 7


def qpow(a, b):
    res = 1
    while b:
        if b & 1:
            res = (res*a) % MOD
        a = (a*a) % MOD
        b >>= 1
    return res


def Solve():
    n, k = map(int, input().split())
    l, r, fact, y = [0]*(10**3+5), [0]*(10**3+5), [0]*(10**3+5), [0]*(10**3+5)
    l[0] = fact[0] = r[k + 3] = 1
    y[0] = 0
    for i in range(1, k+3):
        fact[i] = (fact[i-1]*i) % MOD
        y[i] = (y[i-1]+qpow(i, k)) % MOD
        tmp = (n-i) % MOD
        l[i] = (l[i-1]*tmp) % MOD
    for i in range(k+2, 0, -1):
        tmp = (n-i) % MOD
        r[i] = (r[i+1]*tmp) % MOD
    ans = 0
    for i in range(1, k+3):
        up = (l[i-1]*r[i+1]) % MOD
        up = (up*y[i]) % MOD
        down = (fact[i-1]*fact[k+2-i]*(-1 if (k+2-i) & 1 else 1)) % MOD
        ans += (up*qpow(down, MOD-2)) % MOD
        ans %= MOD
    print((ans+MOD) % MOD)


for _ in range(int(input())):
    Solve()
