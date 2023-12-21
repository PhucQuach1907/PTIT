#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> min_L(n), max_R(n);
    min_L[0] = a[0];
    for (int i = 1; i < n; i++)
        min_L[i] = min(a[i], min_L[i - 1]);
    max_R.back() = a.back();
    for (int i = n - 2; i >= 0; i--)
        max_R[i] = max(a[i], max_R[i + 1]);
    int i = 0, j = 0, ans = -1;
    while (i < n && j < n)
    {
        if (min_L[i] < max_R[j])
        {
            ans = max(ans, j - i);
            j++;
        }
        else
            i++;
    }
    cout << ans << "\n";
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Solve();
    }
    return 0;
}
