#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    vector<int> a(n1), b(n2), c(n3);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    for (auto &x : c)
        cin >> x;
    int i = 0, j = 0, k = 0;
    bool ok = false;
    while (i < n1 && j < n2 && k < n3)
    {
        if (a[i] == b[j] && b[j] == c[k])
        {
            cout << a[i] << " ";
            ok = true;
            i++, j++, k++;
        }
        else if (a[i] < b[j])
            i++;
        else if (b[j] < c[k])
            j++;
        else
            k++;
    }
    if (!ok)
        cout << -1;
    cout << "\n";
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
