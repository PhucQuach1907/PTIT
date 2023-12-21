#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), v;
    for (auto &x : a)
        cin >> x;
    v.push_back(a[0]);
    for (int i = 1; i < n; i++)
    {
        auto pos = lower_bound(v.begin(), v.end(), a[i]);
        if (pos == v.end())
            v.push_back(a[i]);
        else
            *pos = a[i];
    }
    cout << v.size();
    return 0;
}
