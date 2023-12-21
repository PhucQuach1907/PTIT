#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    ll res = (n * (n - 1)) / 2;
    vector<int> a;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == s[i - 1])
            cnt++;
        else
        {
            a.push_back(cnt);
            cnt = 1;
        }
    }
    a.push_back(cnt);
    for (int i = 0; i < a.size() - 1; i++)
        res -= (a[i] + a[i + 1] - 1);
    cout << res;
    return 0;
}
