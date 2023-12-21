#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int Count(int x, int y, int z)
{
    set<int> s;
    s.insert(x), s.insert(y), s.insert(z);
    if (s.size() == 3)
        return 6;
    else if (s.size() == 2)
        return 3;
    return 1;
}
int main()
{
    int k, s;
    cin >> k >> s;
    int cnt = 0;
    for (int i = 0; i <= k; i++)
    {
        for (int j = i; j <= k; j++)
        {
            int tmp = s - i - j;
            cnt += (tmp >= 0 && tmp <= k && tmp >= j ? Count(i, j, tmp) : 0);
        }
    }
    cout << cnt;
    return 0;
}
