#include <iostream>
#include <algorithm>
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    scanf("%d", &n);
    int res = n;
    for (int p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        {
            while (n % p == 0)
                n /= p;
            res -= res / p;
        }
    }
    if (n > 1)
        res -= res / n;
    printf("%d\n", res);
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Solve();
    }
    return 0;
}
