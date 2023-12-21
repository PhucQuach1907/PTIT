#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    while (m--)
    {
        int median = (a.size() + 1) / 2 - 1;
        cout << a[median] << " ";
        a.erase(a.begin() + median);
    }
    return 0;
}
