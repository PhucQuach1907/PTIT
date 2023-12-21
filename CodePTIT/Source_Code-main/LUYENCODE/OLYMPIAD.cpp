#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, c, k;
    scanf("%d%d%d", &n, &c, &k);
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        int skill, intell;
        scanf("%d%d", &skill, &intell);
        int tmp;
        if (intell == 0 && skill >= k)
        {
            tmp = 0;
            a.push_back(tmp);
        }
        else if (intell != 0)
        {
            int need = max(0, k - skill);
            tmp = (need % intell == 0 ? need / intell : need / intell + 1);
            a.push_back(tmp);
        }
    }
    sort(a.begin(), a.end());
    int i = 0, sum = 0, ans = 0;
    while (sum + a[i] <= c && i < a.size())
    {
        ans++;
        sum += a[i];
        i++;
    }
    printf("%d", ans);
    return 0;
}
