#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int sum = accumulate(a.begin(), a.end(), 0) + k;
    if (sum % n != 0)
    {
        cout << "NO\n";
        return;
    }
    sum /= n;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] < sum)
            tmp += (sum - a[i]);
        else if (a[i] > sum)
        {
            cout << "NO\n";
            return;
        }
    }
    cout << (tmp == k ? "YES\n" : "NO\n");
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
