#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector<int> max_L(n), min_R(n);
    max_L[0] = a[0], min_R[n - 1] = a[n - 1];
    for (int i = 1, j = n - 2; i < n, j >= 0; i++, j--)
    {
        max_L[i] = max(a[i], max_L[i - 1]);
        min_R[j] = min(a[j], min_R[j + 1]);
    }
    sort(a.begin(), a.end());
    vector<int> pos;
    for (int i = 0; i < n - 1; i++)
    {
        if (max_L[i] == a[i] && min_R[i + 1] == a[i + 1])
            pos.push_back(i + 1);
    }
    printf("%d\n", pos.size());
    for (auto x : pos)
        printf("%d ", x);
    printf("\n");
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
