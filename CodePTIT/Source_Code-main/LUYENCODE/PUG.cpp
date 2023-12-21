#include <stdio.h>
#include <math.h>
#include <iostream>
#define ll long long
int Last_Digit(ll n)
{
    if (n == 0)
        return 1;
    if (n % 4 == 0)
        return 6;
    if (n % 4 == 1)
        return 2;
    if (n % 4 == 2)
        return 4;
    return 8;
}
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    ll n;
    scanf("%lld", &n);
    int ans = Last_Digit(n) + 1;
    printf("%d", ans);
    return 0;
}
