#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for (auto &c : a)
            cin >> c;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
            v.push_back({abs(x - a[i]), i});
        sort(v.begin(), v.end(), cmp);
        for (int i = 0; i < v.size(); i++)
            cout << a[v[i].second] << " ";
        cout << "\n";
    }
    return 0;
}