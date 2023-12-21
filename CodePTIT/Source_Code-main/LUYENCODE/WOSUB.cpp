#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    int s;
    cin >> s;
    int start = 0, res = -1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        while (sum >= s)
        {
            if (sum == s)
            {
                res = max(res, i - start + 1);
                break;
            }
            else
            {
                sum -= a[start];
                start++;
            }
        }
    }
    cout << res;
    return 0;
}
