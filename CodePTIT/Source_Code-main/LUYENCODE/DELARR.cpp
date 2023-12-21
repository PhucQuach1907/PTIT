#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    long sum_am = 0, sum_duong = 0, a[100005], chisodau = 1, chisocuoi;
    int n, socach = 0;
    scanf("%d", &n);
    chisocuoi = n;
    for (int i = 1; i <= n; i++)
    {
        scanf("%li", &a[i]);
        if (a[i] > 0)
            sum_duong += a[i];
        else if (a[i] < 0)
            sum_am += a[i];
    }
    if (sum_duong == 0 || sum_am == 0)
    {
        if (sum_duong == 0)
            socach = sum_am * (-1);
        else
            socach = sum_duong;
    }
    else
    {
        sort(a + 1, a + n + 1);
        while (sum_duong != sum_am * (-1))
        {
            if (sum_duong > sum_am * (-1))
            {
                sum_duong -= a[chisocuoi];
                chisocuoi--;
                socach++;
            }
            else if (sum_duong < sum_am * (-1))
            {
                sum_duong -= a[chisodau];
                chisodau++;
                socach++;
            }
        }
    }
    printf("%d", socach);
    return 0;
}
