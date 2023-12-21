#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 2; i++)
    {
        int l = i + 1, r = n - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == k)
            {
                printf("YES\n");
                return;
            }
            else if (a[i] + a[l] + a[r] > k)
                r--;
            else
                l++;
        }
    }
    printf("NO\n");
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        Solve();
    }
    return 0;
}
