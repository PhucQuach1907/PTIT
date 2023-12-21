#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Last_Digit(int a, int n)
{
    if (n == 0 || a == 1)
        return 1;
    a %= 10;
    int exp = (n % 4 == 0 ? 4 : n % 4);
    int res = pow(a, exp);
    return (res % 10);
}
int main()
{
    int a, n;
    cin >> a >> n;
    cout << Last_Digit(a, n);
    return 0;
}
