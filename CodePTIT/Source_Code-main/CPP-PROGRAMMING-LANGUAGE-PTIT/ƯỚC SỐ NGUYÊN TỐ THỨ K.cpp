#include <bits/stdc++.h>
using namespace std;
#define ui64 unsigned long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a;
        while (n % 2 == 0)
        {
            n /= 2;
            a.push_back(2);
        }
        for (int i = 3; i <= sqrt(n); i++)
        {
            while (n % i == 0)
            {
                n /= i;
                a.push_back(i);
            }
        }
        if (n > 2)
            a.push_back(n);
        if (k > a.size())
            cout << -1 << "\n";
        else
            cout << a[k - 1] << "\n";
    }
    return 0;
}
