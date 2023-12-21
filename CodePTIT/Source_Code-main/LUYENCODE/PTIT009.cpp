#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Minimum_Step(vector<string> a, int n, string s)
{
    string tmp = s + s;
    int len = s.size();
    vector<int> pos(n);
    for (int i = 0; i < n; i++)
    {
        int p = tmp.find(a[i]);
        if (p == -1)
            return -1;
        pos[i] = ++p;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans += (pos[i] == 1 ? 0 : 1 + len - pos[i]);
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<string> a(n);
    for (auto &x : a)
        cin >> x;
    int res = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int tmp = Minimum_Step(a, n, a[i]);
        if (tmp != -1)
            res = min(res, tmp);
    }
    cout << (res == INT_MAX ? -1 : res);
    return 0;
}
