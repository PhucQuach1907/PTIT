#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;
    map<int, bool> exist;
    exist[a[0]] = true;
    for (int i = 1; i < n; i++)
    {
        auto tmp = exist;
        for (auto x : tmp)
            exist[x.first + a[i]] = true;
        exist[a[i]] = true;
    }
    for (auto x : b)
        cout << (exist[x] ? "1" : "0");
    return 0;
}
