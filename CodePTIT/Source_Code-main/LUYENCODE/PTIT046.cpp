#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void Fact(int n, map<int, int> &mp)
{
    while (n % 2 == 0)
    {
        n /= 2;
        mp[2]++;
    }
    for (int i = 3; i <= sqrt(n); i += 2)
    {
        while (n % i == 0)
        {
            n /= i;
            mp[i]++;
        }
    }
    if (n > 2)
        mp[n]++;
}
bool Check(map<int, int> mpn, map<int, int> mpm)
{
    for (auto x : mpn)
    {
        int tmp = x.first;
        if (tmp != 2 && tmp != 3 && tmp != 5)
        {
            if (mpm[tmp] != mpn[tmp])
                return false;
        }
    }
    return true;
}
int main()
{
    int n, m;
    cin >> n >> m;
    if (n == m)
    {
        cout << 0;
        return 0;
    }
    map<int, int> mpn, mpm;
    Fact(n, mpn);
    Fact(m, mpm);
    if (!Check(mpn, mpm) || !Check(mpm, mpn))
    {
        cout << -1;
        return 0;
    }
    int ans = 0;
    ans += abs(mpn[2] - mpm[2]);
    ans += abs(mpn[3] - mpm[3]);
    ans += abs(mpn[5] - mpm[5]);
    cout << ans;
    return 0;
}
