#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    unordered_map<int, int> pos;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        pos[x] = i + 1;
    }
    cout << pos[k] << "\n";
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
