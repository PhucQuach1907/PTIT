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
        int n, res = 0;
        cin >> n;
        vector<int> a(n);
        for (auto &c : a)
            cin >> c;
        int i = 0, j = n - 1;
        while (i <= j)
        {
            if (a[i] == a[j])
            {
                i++;
                j--;
            }
            else if (a[i] < a[j])
            {
                i++;
                a[i] += a[i - 1];
                res++;
            }
            else
            {
                j--;
                a[j] += a[j + 1];
                res++;
            }
        }
        cout << res << "\n";
    }
    return 0;
}