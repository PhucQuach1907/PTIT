#include <bits/stdc++.h>
using namespace std;
int Mini_Jumps(int a[], int n)
{
    if (a[0] == 0)
        return -1;
    if (n == 1)
        return 0;
    int res = 1, remain = a[0], maxreach = a[0];
    for (int i = 1; i < n; i++)
    {
        if (i == n - 1)
            return res;
        maxreach = max(maxreach, i + a[i]);
        remain--;
        if (remain == 0)
        {
            res++;
            if (i >= maxreach)
                return -1;
            remain = maxreach - i;
        }
    }
    return -1;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << Mini_Jumps(a, n) << "\n";
    }
    return 0;
}