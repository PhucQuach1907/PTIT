#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, res = 0;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    vector<int> left(n, 0), right(n, 0);
    for (int i = 0; i < n; i++)
    {
        left[i] = a[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (a[i] > a[j])
                left[i] = max(left[i], left[j] + a[i]);
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        right[i] = a[i];
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                right[i] = max(right[i], right[j] + a[i]);
        }
    }
    for (int i = 0; i < n; i++)
        res = max(res, left[i] + right[i] - a[i]);
    cout << res << "\n";
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
