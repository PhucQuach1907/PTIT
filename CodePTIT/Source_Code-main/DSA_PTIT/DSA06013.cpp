#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &A : a)
        cin >> A;
    int cnt = count(a.begin(), a.end(), x);
    cout << (cnt == 0 ? -1 : cnt) << "\n";
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
