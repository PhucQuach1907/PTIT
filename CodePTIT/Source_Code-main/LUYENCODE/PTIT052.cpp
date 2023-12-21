#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Calc(int box, int k)
{
    if (box < k)
        return 0;
    return (box / k + Calc((box / k) + (box % k), k));
}
int main()
{
    int n, k;
    cin >> n >> k;
    cout << n + Calc(n, k);
    return 0;
}
