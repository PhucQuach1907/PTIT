#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    scanf("%d", &n);
    string ans = "";
    if (n == 1)
    {
        printf("1\n");
        return;
    }
    for (int i = 9; i > 1; i--)
    {
        while (n % i == 0)
        {
            n /= i;
            ans += to_string(i);
        }
    }
    if (n != 1)
        printf("-1\n");
    else
    {
        for (int i = (int)ans.size() - 1; i >= 0; i--)
            printf("%c", ans[i]);
        printf("\n");
    }
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Solve();
    }
    return 0;
}
