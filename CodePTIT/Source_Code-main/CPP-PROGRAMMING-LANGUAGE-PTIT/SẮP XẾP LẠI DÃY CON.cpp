#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (auto &c : a)
            cin >> c;
        b.assign(a.begin(), a.end());
        sort(a.begin(), a.end());
        int start = 0, end = n - 1, ok1 = 1, ok2 = 1;
        while (start <= end)
        {
            if (!ok1 && !ok2)
                break;
            ok1 = (a[start] != b[start] ? 0 : ok1);
            start += (ok1 ? 1 : 0);
            ok2 = (a[end] != b[end] ? 0 : ok2);
            end -= (ok2 ? 1 : 0);
        }
        cout << start + 1 << " " << end + 1 << "\n";
    }
    return 0;
}