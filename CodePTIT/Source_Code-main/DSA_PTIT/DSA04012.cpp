#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> A(n), B(m), res(n + m - 1, 0);
    for (auto &x : A)
        cin >> x;
    for (auto &x : B)
        cin >> x;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            res[i + j] += (A[i] * B[j]);
    }
    for (auto x : res)
        cout << x << " ";
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
