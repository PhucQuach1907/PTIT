#include <stdio.h>
#include <math.h>
#include <iostream>
#define ll long long
int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    ll n, a, b;
    scanf("%lld%lld%lld", &n, &a, &b);
    ll ans = ceil((-2 * a - b + sqrt(4 * a * a + b * b - 4 * a * b + 8 * b * n)) / (2 * b));
    printf("%lld", ans + 1);
    return 0;
}
