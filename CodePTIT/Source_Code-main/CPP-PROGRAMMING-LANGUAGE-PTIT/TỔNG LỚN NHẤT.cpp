#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int Largest_Sum(int a[], int b[], int n, int m)
{
    int sum = 0, res;
    for (int i = 0; i < n; i++)
        sum += a[i];
    res = sum;
    for (int i = 0; i < m; i++)
    {
        sum += (b[i] - a[i]);
        res = max(res, sum);
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        if (n > m)
            cout << Largest_Sum(a, b, n, m);
        else if (n < m)
            cout << Largest_Sum(b, a, m, n);
        else
            cout << max(Largest_Sum(a, b, n, m), Largest_Sum(b, a, m, n)) << "\n";
    }
    return 0;
}