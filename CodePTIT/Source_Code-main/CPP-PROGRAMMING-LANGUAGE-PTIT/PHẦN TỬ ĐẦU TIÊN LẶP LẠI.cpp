#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n + 1];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        set<int> diff;
        int index;
        for (int i = 1; i <= n; i++)
        {
            diff.insert(a[i]);
            if (i - diff.size() == 1)
            {
                index = i;
                break;
            }
        }
        cout << (diff.size() == n ? -1 : a[index]) << "\n";
    }
    return 0;
}